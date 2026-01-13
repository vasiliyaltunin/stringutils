/**
 * @example examples/basic/main.cpp Файл содержит пример использования класса StringUtils
 * @file main.cpp
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит пример использования класса StringUtils
 * @version 0.1.0
 * @date 2025-09-05
 *
 * @copyright Алтунин Василий 2025
 *
 * Демонстрирует применения класса StirngUrils
 * обрезая лишние пробелы в строке и разделяя строку на части,
 * а так же создание логина из ФИО
 *
 */

#include <iostream>
#include <string>

#include <clocale>

#include <fcntl.h>
#include <io.h>


#include "../../include/stringutils/stringutils.h"

using namespace altuninvv::string;

int main(int argc, char *argv[]) {

  std::cout << "\n--- EN ---\n";


  // Пример работы методов trim
  StringUtils<std::string> s;

  std::string str = "  HELLO WORLD   ";
  std::cout << "\n|" << str << "|";

  // Пример работы с rtrim()
  str = s.rtrim(str);
  std::cout << "\n|" << str << "|\n";

  str = "  HELLO WORLD   ";
  std::cout << "\n|" << str << "|";

  // Пример работы с ltrim()
  str = s.ltrim(str);
  std::cout << "\n|" << str << "|\n";


  str = "  HELLO WORLD   ";
  std::cout << "\n|" << str << "|";

  
  // Пример работы с trim()
  str = s.trim(str);
  std::cout << "\n|" << str << "|\n";


  str = "HELLO MY NEW PERFECT WORLD";
  std::cout << "\n|" << str << "|";

  StringUtils<std::string>::strlist result;

  // Пример работы метода split
  result = s.split(str, " ");

  std::cout << "\n";

  for (std::string s : result) {
    std::cout << s << " = ";
  }

  std::cout << "\n\n--- RUS ---\n";

  // Пример работы c русскими строками через std::wstring

    // Обязательно устанавливаем настройки локали UTF-8
  _setmode(_fileno(stdout), _O_U16TEXT);
  _setmode(_fileno(stdin), _O_U16TEXT);
  _setmode(_fileno(stderr), _O_U16TEXT);

  // Обязательно устанавливаем русскую локаль
  setlocale(LC_ALL, "Russian");


  StringUtils<std::wstring> s1;

  std::wstring str1 = L"  ПРИВЕТ МИР   ";
  std::wcout << "\n|" << str1.c_str() << "|";

  str1 = s1.rtrim(str1);
  std::wcout << "\n|" << str1 << "|\n";
  
  str1 = L"  ПРИВЕТ МИР   ";
  std::wcout << "\n|" << str1.c_str() << "|";
  
  str1 = s1.ltrim(str1);
  std::wcout << "\n|" << str1 << "|\n";

  str1 = L"  ПРИВЕТ МИР   ";
  std::wcout << "\n|" << str1.c_str() << "|";

  str1 = s1.trim(str1);
  std::wcout << "\n|" << str1 << "|\n";


  str1 = L"ПРИВЕТ МОЙ НОВЫЙ|ИДЕАЛЬНЫЙ МИР";
  std::wcout << "\n|" << str1 << "|\n";

  StringUtils<std::wstring>::strlist result1;

  result1 = s1.split(str1, L"|");

  for (std::wstring s : result1) {
    std::wcout << s << "=";
  }


  str1 = L"ПРИВЕТ МОЙ НОВЫЙ ИДЕАЛЬНЫЙ МИР";
  std::wcout << "\n\n|" << str1 << "|\n";

  result1 = s1.split(str1, L" ");

  for (std::wstring s : result1) {
    std::wcout << s << "=";
  }

  // Пример создания логина
  std::wstring sourceFIO = L"Иванов Семен Петрович";
  std::wcout << "\n\n|" << sourceFIO << "|";


  std::wstring fio1 = s1.makeLogin(sourceFIO, L" ");

  std::wcout << "\n|" << fio1 << "|\n";

  return 0;
}
