/*
customer.hpp
определения функций-членов класса клиента
*/

#include "customer.h"
#include <string>

// функция для форматирования даты в yyyy-mm-dd
std::string customer::format_date()
{
    std::string date = std::to_string(customer::last_visit);
    std::string date_form = date.substr(0,4) + "-" + date.substr(4,2) + "-" + date.substr(6,2);
    return date_form;
}