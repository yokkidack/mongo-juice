/* Copyright Igor Roshchin
//  __    __ _____ _____ ___   _____
// |   \/   |     |   | |  _|_|     | contact me: mosgreyday@gmail.com
// |  |\/|  |  |  | | | |   | |  |  | "mongo_agent_nice.hpp"
// |__|  |__|_____|_|___|_____|_____| just some things to make
//                                    mongo_agent nicer
//
// TODO:
// --yaaaaay nothing to do here
*/

/*!
\file "mongo_agent_nice.hpp"
\brief Заголовочный файл с описанием полезных и простых функций
\author Рощин Игорь (Roshchin Igor)
\copyright MIT License
\todo all todos are complete as today
"just some things to make mongo_agent nicer"
Данный заголовочный файл с описанием полезных и простых функций 
*/
#ifndef INCLUDE_MONGO_AGENT_NICE_HPP_
#define INCLUDE_MONGO_AGENT_NICE_HPP_

#include <fstream>
#include <string>
/*!
\brief Сохраняет предоставленную строку (строковый документ) в файл
\param[doc]      doc      Строка или строковый документ, 
                          который предстоит сохранить
\param[filename] filename Имя файла, куда нужно сохранить
*/
auto doc_string_to_file(std::string doc, std::string filename) -> void
{
    std::ofstream o(filename);
    o << doc;
    o.close();
}
/*!
\brief Функция для нахождения длины числа
\param[num]      num      Число, длину которого нужно найти
*/
auto number_length(int num) -> unsigned int
{
    if (!num) return 1;
    int i = 1;
    for (; i < num; i++) num /= 10;
    return i;
}

/*!
\brief Функция для создания более красивых имен файлов из номера
\param[i]      i      Номер, из которого будет создано имя
*/
auto nicer_file_numbers_from_i(int i) -> std::string
{
    std::string s{ std::to_string(i) };
    unsigned long int a = 10 - s.length();
    std::string out(a, '0');
    return out + s;
}
/*!
\brief          Возвращает случайную строку заданной длинны
\param[length]      length  Длина желаемой строки 
*/
auto get_random_string(unsigned int length) -> std::string
{
std::string string{""};
for (unsigned int i = 0; i < length; i++) {
         int randomChar = rand()%(26+26+10);
         if (randomChar < 26)
             string += 'a' + randomChar;
         else if (randomChar < 26+26)
             string += 'A' + randomChar - 26;
         else
             string += '0' + randomChar - 26*2;
     }
return string;
}
/*!
\brief          Возвращает строку из пары ключ - значение заданных длин
\param[key_length]      key_length  Длина желаемого ключа 
\param[value_length]      value_length  Длина желаемого значения 

*/
auto get_random_key_eq_value_string(unsigned int key_length, unsigned int value_length) -> std::string
{
    return {get_random_string(key_length) + '=' + get_random_string(value_length)};
}

#endif // INCLUDE_MONGO_AGENT_NICE_HPP_