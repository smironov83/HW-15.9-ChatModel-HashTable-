#include "chat.h"

Chat::Chat()
{
  _count = 0;
  _delCount = 0;
  _mem_size = 10;
  _array = new AuthData[_mem_size];
}

Chat::~Chat() { delete[]_array; }

void Chat::reg(LoginName login, std::string const password)
{
  {
    size_t index = -1, i = 0;
    //Берет пробы по всем i от 0 до размера массива
    for (; i < _mem_size; i++)
    {
      index = hash_func(login, i);
      //Если находит пустую ячейку - занимает ее
      if (_array[index]._status != enPairStatus::engaged)
        break;
    }
    
    //Если место отсутствует увеличивает хеш-таблицу вдвое, иначе добавляет
    if (i >= _mem_size) 
    {
      resize();
      reg(login, password);
    }
    else {
      _array[index] = AuthData(login, password);
      _count++;
    }
  }
}

void Chat::del(LoginName login)
{
  size_t index = -1, i = 0;
  //Берет пробы по всем i от 0 до размера массива
  for (; i < _mem_size; i++) {
    index = hash_func(login, i);
    if (_array[index]._status == enPairStatus::engaged &&
      !strcmp(_array[index]._login, login)) {
      _array[index]._status = enPairStatus::deleted;
      _count--;
      _delCount++;
      if (_delCount > _mem_size / 2)
        delDeleted();
      return;
    }
    else 
      if (_array[index]._status == enPairStatus::free) 
        return; 
  }
}

auto Chat::find(LoginName login)->std::string const
{
  for (size_t i = 0; i < _mem_size; i++) {
    size_t index = hash_func(login, i);
    if (_array[index]._status == enPairStatus::engaged &&
      !strcmp(_array[index]._login, login)) 
          return _array[index]._password;
    else if (_array[index]._status == enPairStatus::free) {
      return "Login не найден!!!";
    }
  }
  return "Login не найден!!!";
}

void Chat::resize()
{
  AuthData* save = _array;
  size_t save_ms = _mem_size;
  _mem_size *= 2;
  _array = new AuthData[_mem_size];
  _count = 0;

  for (size_t i = 0; i < save_ms; i++) 
  {
    AuthData& old_pair = save[i];
    if (old_pair._status == enPairStatus::engaged) 
      reg(old_pair._login, old_pair._password);
  }
  delete[] save;
}

void Chat::delDeleted()
{
  for (size_t i = 0; i < _mem_size; ++i)
    if (_array[i]._status == enPairStatus::deleted)
      _array[i] = AuthData();
}

auto Chat::get_memsize() const->size_t
{ return _mem_size; }

auto Chat::get_array_login(size_t i) const->LoginName&
{ return _array[i]._login; }

auto Chat::hash_func(LoginName login, size_t offset)->size_t
{
  //Вычисляет индекс
  int sum = 0, i = 0;
  for (; i < strlen(login); i++)
    sum += login[i];

  //Метод умножения
  sum = int(LOGINLENGTH * (HASHCOEFMULTI * sum - int(HASHCOEFMULTI * sum)));

  //Квадратичные пробы
  return (sum % _mem_size + offset * offset) % _mem_size;
}

Chat::AuthData::AuthData() : _login(""), _password(""),
_status(enPairStatus::free) {}

Chat::AuthData::AuthData(LoginName login, std::string const password) :
  _password(password), _status(enPairStatus::engaged)
{
  strcpy_s(_login, login);
}

auto Chat::AuthData::operator=(const Chat::AuthData& other)->Chat::AuthData&
{
  _password = other._password;
  strcpy_s(_login, other._login);
  _status = other._status;
  return *this;
}