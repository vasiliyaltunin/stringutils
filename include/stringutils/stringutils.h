/**
 * @file stringutils.h
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит объявление и реализацию класса StringUtils
 * @version 0.1.0
 * @date 07.01.2026
 * @bug Багов не обнаружено
  *
 * @copyright Алтунин Василий 2026
 *
 * Файл содержит реализацию класса-шаблона StringUtils реализующего обработку
 * строк
 *
 * @example examples/basic/main.cpp Файл содержит пример использования класса StringUtils
 *
 */

#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <list>

#pragma once

/**
 * @brief Пространство имён altuninvv::string содержит классы и функции для 
 обработки строк
 *
 */
namespace altuninvv::string {

/**
 * @brief Шаблон класса для обработки строк 
 * 
 * @tparam T - может быть std::string или std::wstring
 * @code {.cpp}
 * StringUtils<std::string> s;
 *
 * StringUtils<std::wstring> ws;
 * @endcode
 * @bug Багов не обнаружено
 * @details 
 * Класс-шаблон для обработки строк std::string или std::wstring
 * реализует методы: ltrim(), rtrim(), trim(), split().

 * Метод makeLogin() позволяет преобразовывать ФИО в логин.
 * 
 * @warning Нет предупреждений
 */
template <typename T> class StringUtils {

public:
 /**
 * @brief Список для использования с классом шаблономы
 * 
 */
  typedef std::list<T> strlist;

  /**
   * @brief Символы, которые будут вырезаться из строки при 
   использовании методов trim():
   Пробел, табулящия, новая строка, перевод каретки.
   * 
   */
  const char *TRIMABLES = " \t\n\r";

  /**
   * @brief Конструктор класса StringUtils
   *
   */
  explicit StringUtils() {};

  /**
   * @brief Деструктор класса StringUtils
   *
   */
  ~StringUtils() {};

  /**
   * @brief Обрезает все пробелы справа от строки
   * 
   * @param sourceStr - строка для обработки
   * @return T - результат
   */
  T rtrim(T sourceStr) {

    sourceStr.erase(sourceStr.find_last_not_of(*TRIMABLES) + 1);

    return sourceStr;
  }

  /**
   * @brief Обрезает все пробелы слева от строки
   * 
   * @param sourceStr - строка для обработки
   * @return T - результат
   */
  T ltrim(T sourceStr) {

    sourceStr.erase(0, sourceStr.find_first_not_of(*TRIMABLES));

    return sourceStr;
  }

  /**
   * @brief Обрезает пробелы справа и слева от строки 
   * 
   * @param sourceStr - строка для обработки
   * @return T - результат
   */
  T trim(T sourceStr) {
    T result = StringUtils::ltrim(StringUtils::rtrim(sourceStr));

    return result;
  }

   /**
   * @brief Разбивает сроку на части используя разделитель 
   * 
   * @param sourceStr - строка для обработки
   * @param splitter - строка содержащя разделитель
   * @return StringUtils<T>::strlist - результат
   */
  StringUtils<T>::strlist split(T sourceStr, T splitter) {

    StringUtils<T>::strlist data;
    T tmp;

    for (auto i : sourceStr) {

      if (i == splitter[0]) {
        data.insert(data.end(), tmp);
        tmp.clear();
      } else {
        tmp.append(1, i);
      }
    }
    data.insert(data.end(), tmp);

    return data;
  }

  /**
  
   * @brief Разбивает строку с ФИО на 3 части и формирует из них логин вида 
   * ИвановИИ
   *
   * @param sourceStr - строка для обработки
   * @param splitter - строка содержащя разделитель
 
   * @return T - результат в виде логина
   */
  T makeLogin(T sourceStr, T splitter) {

    sourceStr = this->trim(sourceStr);

    StringUtils<T>::strlist fio = this->split(sourceStr, splitter);

    T result;

    int j = 0;

    for (auto i : fio) {
      switch (j) {
      case 0: {
        result += i;
        break;
      }
      case 1: {
        result += i[0];
        break;
      }
      case 2: {
        result += i[0];
        break;
      }
      }
      j++;
    }

    return result;
  }

private:
};

} // namespace altuninvv::string
#endif
