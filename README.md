# HW-15.9-ChatModel(HashTable)
Модель чата с хеш-таблицей хранения пар логин/пароль - это домашнее задание по 15 модулю блока "Алгоритмы и структуры данных" 
курса «Разработчик на C++» от oнлайн-школы SkillFactory.

#  Список команды:
|  Логин        |  Фамилия Имя 
| ------        | ------                                                   
| smironov83    | Миронов Сергей        

`smironov83` - All-in-one

В ChatModel(HashTable) реализовано:
- Хранение пар логин (ключ) и хеш пароля в хеш-таблице.
- Хеш-функция методом умножения
- Хеш-таблица методом квадратичного пробирования
- Принцип инкапсуляции
- Решение проблемы большого количества удаленных элементов в хеш-таблице в виде очистки от удаленных элементов и перехеширования таблицы.

#  Классы, реализованные в UnworkableChat

| Class    | Including                                                                                                                                     |
| ------   | ------                                                                                                                                        |
| Chat     | public: `struct AuthData`, `void reg`, `void del`, `auto find`, `void resize`, `void delDeleted`, `auto get_memsize`, `auto get_array_login`, |
|          | private: `enum enPairStatus`, `auto hash_func`, `AuthData* _array`, `size_t _mem_size, _count, _delCount`                                     |
| AuthData | `auto operator =`, `LoginName _login`, `std::string _password`, `enPairStatus _status`                                                        |
