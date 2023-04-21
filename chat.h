#pragma once
#include <string>

//Фиксирует длину имени
constexpr auto LOGINLENGTH = 20;
//Коэффициент для метода умножения хеш-функции
constexpr auto HASHCOEFMULTI = 0.6180339887;

typedef char LoginName[LOGINLENGTH]; //Тип имя логина

class Chat //Хеш-таблица
{
public:
  Chat(); //Конструктор
  ~Chat(); //Деструктор
  //Добавляет пару логин/пароль
  void reg(LoginName login, std::string const password);
  //Удаляет пару по логину
  void del(LoginName login);
  //Ищет пару по логину
  auto find(LoginName login)->std::string const;
  //Увеличивает массив вдвое, в случае переполнения
  void resize();
  //Заменяет удаленные элементы на свободные
  void delDeleted();
  //Геттеры/сеттеры
  auto get_memsize() const->size_t;
  auto get_array_login(size_t i) const->LoginName&;

private:
  //Статус пары элемента хеш-таблицы: свободен, занят, удален
  enum enPairStatus { free, engaged, deleted };
  //Пара логин-пароль
  struct AuthData 
  {
    //Конструктор по умолчанию
    AuthData();

    //Конструктор копирования
    AuthData(LoginName login, std::string const password);
    //Оператор присваивания
    auto operator = (const AuthData& other)->AuthData&;

    //Деструктор
    ~AuthData() {};

    LoginName _login{};
    std::string _password;
    enPairStatus _status;
  };
  auto hash_func(LoginName login, size_t offset) -> size_t;

  AuthData* _array{};
  size_t _mem_size = 0;
  size_t _count = 0;
  size_t _delCount = 0;
};