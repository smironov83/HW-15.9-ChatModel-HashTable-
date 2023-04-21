#include "chat.h"
#include "iostream"

auto main() -> int
{
  system("chcp 1251");
  system("cls");

  Chat users;
  users.reg((char*)"qwerty1", "qwerty");
  users.reg((char*)"qwerty2", "qwerty");
  users.reg((char*)"qwerty3", "qwerty");
  users.reg((char*)"qwerty4", "qwerty1");
  users.reg((char*)"qwerty5", "qwerty1");
  users.reg((char*)"qwerty6", "qwerty1");
  users.reg((char*)"qwerty7", "qwerty2");
  users.reg((char*)"qwerty8", "qwerty2");
  users.reg((char*)"qwerty9", "qwerty2");
  users.reg((char*)"qwerty10", "qwerty3");
  users.reg((char*)"qwerty11", "qwerty3");
  users.reg((char*)"qwerty12", "qwerty3");
  users.reg((char*)"qwerty13", "qwerty4");
  users.reg((char*)"qwerty14", "qwerty4");
  users.reg((char*)"qwerty15", "qwerty4");
  users.reg((char*)"qwerty16", "qwerty5");
  users.reg((char*)"qwerty17", "qwerty5");
  users.reg((char*)"qwerty18", "qwerty5");
  users.reg((char*)"qwerty19", "qwerty6");
  users.reg((char*)"qwerty20", "qwerty6");

  for (size_t i = 0; i <= users.get_memsize() / 2; ++i)
    users.del(users.get_array_login(i));
  std::cout << users.find((char*)"qwerty1") << std::endl;
  std::cout << users.find((char*)"qwerty20") << std::endl;
  std::cout << users.get_memsize() << std::endl;

  return 0;
}