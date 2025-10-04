/* cust_table.h
класс таблицы клиентов для crm
наследуется от базового класса таблицы */

// избежать повторной загрузки файла
#ifndef __cust_table_H_INCLUDED__ 
#define __cust_table_H_INCLUDED__ 

#include <iostream>
#include "table.h"
#include "customer.hpp"

using namespace std;

class cust_table : public table<int,customer>  {
    public:
        std::string filename;

        // конструктор (присвоить параметры и заполнить таблицу данными при создании класса)
        cust_table(std::string i_filename)
        :filename(i_filename)
        {cust_table::read_data();};
        // деструктор (сохранить данные в локальную базу данных и очистить таблицу в памяти)
        ~cust_table() {
            write_data();
            hashtable.clear();
        }
        // функции-члены
        void print_table(int n_rows);
        void read_data();
        void write_data();
        int get_max_id();
        int get_total_sales();
};

// наследуется от шаблонного класса, вкл скрипт определений класса внизу
#include "cust_table.hpp"

#endif