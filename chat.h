#pragma once
#include "string"

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
  void reg(LoginName login, std::string password);
  //Удаляет пару по логину
  void del(LoginName login);
  //Ищет пару по логину
  auto find(LoginName login)->std::string;
  //Увеличивает массив вдвое, в случае переполнения
  void resize();
  //Геттеры/сеттеры
  auto get_memsize() const->int;
  auto get_array_login(size_t i) const->LoginName&;

private:
  enum enPairStatus { free, engaged, deleted };

  struct AuthData //пара логин-пароль
  {
    //Конструктор по умолчанию
    AuthData();

    //Конструктор копирования
    AuthData(LoginName login, std::string password);

    //Оператор присваивания
    auto operator = (const AuthData& other)->AuthData&;

    //Деструктор
    ~AuthData() {};

    LoginName _login{};
    std::string _password;
    enPairStatus _status;
  };
  auto hash_func(LoginName login, int offset) -> int;

  AuthData* _array{};
  int _mem_size = 0;
  int _count = 0;
  int _delCount = 0;
};