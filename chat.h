#pragma once
#include "string"

//��������� ����� �����
constexpr auto LOGINLENGTH = 20;
//����������� ��� ������ ��������� ���-�������
constexpr auto HASHCOEFMULTI = 0.6180339887;

typedef char LoginName[LOGINLENGTH]; //��� ��� ������

class Chat //���-�������
{
public:
  Chat(); //�����������
  ~Chat(); //����������
  //��������� ���� �����/������
  void reg(LoginName login, std::string password);
  //������� ���� �� ������
  void del(LoginName login);
  //���� ���� �� ������
  auto find(LoginName login)->std::string;
  //����������� ������ �����, � ������ ������������
  void resize();
  //�������/�������
  auto get_memsize() const->int;
  auto get_array_login(size_t i) const->LoginName&;

private:
  enum enPairStatus { free, engaged, deleted };

  struct AuthData //���� �����-������
  {
    //����������� �� ���������
    AuthData();

    //����������� �����������
    AuthData(LoginName login, std::string password);

    //�������� ������������
    auto operator = (const AuthData& other)->AuthData&;

    //����������
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