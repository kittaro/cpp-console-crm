/*
cust_table.hpp
определения функций-членов для класса cust_table
*/

#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "cust_table.h"

// функция для получения максимального id в таблице клиентов
//int cust_table::get_max_id() {
    //return hashtable.end()->first;
//}
int cust_table::get_max_id() {
    int max_id = 0;
    for (auto it = hashtable.begin(); it != hashtable.end(); ++it) {
        if (it->second.id > max_id) {
            max_id = it->second.id;
        }
    }
    return max_id;
}

// напечатать таблицу клиентов в аккуратно отформатированном виде
void cust_table::print_table(int n_rows) {
    // основной заголовок
    cout << std::left << "|" << std::setw(85) << std::setfill('-') << "-" << "|" << endl
    << "|" << std::setw(85) << std::setfill(' ') << " " << "|" << endl
    << "|" << std::setw(85) << "Nuts n' Bolts Customer Management System" << "|" << endl
    << "|" << std::setw(85) << std::setfill(' ') << " " << "|" << endl;

    // начать строку заголовков
    cout << "|" << std::setw(5) << std::setfill('=') << "="
    << "|" << std::setw(20) << "="
    << "|" << std::setw(15) << "="
    << "|" << std::setw(10) << "="
    << "|" << std::setw(15) << "="
    << "|" << std::setw(15) << "="
    << "|" << std::setfill(' ') << endl;

    // заголовки столбцов
    std::cout << std::left
    << "|" << std::setw(5) << "ID"
    << "|" << std::setw(20) << "Name"
    << "|" << std::setw(15) << "City"
    << "|" << std::setw(10) << "State"
    << "|" << std::setw(15) << "Last Visit"
    << "|" << std::setw(15) << "Total Sales"
    << "|" << endl
    << "|" << std::setw(5) << std::setfill('=') << "="
    << "|" << std::setw(20) << "="
    << "|" << std::setw(15) << "="
    << "|" << std::setw(10) << "="
    << "|" << std::setw(15) << "="
    << "|" << std::setw(15) << "="
    << "|" << std::setfill(' ') << endl;
    int iter = 0;
    // напечатать строки таблицы
    for (auto it = hashtable.begin(); it != hashtable.end(); ++it, ++iter) {
            if (iter == n_rows) {
                cout << "Showing " + std::to_string(iter) + " of " + std::to_string(hashtable.size()) + " customers." << endl;
                break;
            }
            cout << std::left 
            << "|" << std::setw(5) << it -> first 
            << "|" << std::setw(20) << it->second.name 
            << "|" << std::setw(15) << it->second.city
            << "|" << std::setw(10) << it->second.state
            << "|" << std::setw(15) << it->second.format_date()
            << "|" << std::setw(15) << "$" + std::to_string(it->second.total_sales)
            << "|" << endl
            << "|" << std::setw(5) << std::setfill('-') << "-"
            << "|" << std::setw(20) << "-"
            << "|" << std::setw(15) << "-"
            << "|" << std::setw(10) << "-"
            << "|" << std::setw(15) << "-"
            << "|" << std::setw(15) << "-"
            << "|"
            << std::setfill(' ')
            << endl;
        }
    if (iter >= hashtable.size()) {
        cout << "Showing all customers" << endl;
    }
}

// записать таблицу клиентов в локальную базу данных
void cust_table::write_data() {
    // использование потока для вывода в имя файла
    std::ofstream ofs;
    // открыть поток с опцией trunc для стирания старых данных
    ofs.open(cust_table::filename,ofstream::trunc);
    for (auto it = hashtable.begin(); it != hashtable.end(); ++it) {
            // записать каждый элемент в таблице клиентов в csv
            ofs << it->first << ',';
            ofs << it->second.name << ',';
            ofs << it->second.city << ',';
            ofs << it->second.state << ',';
            ofs << it->second.last_visit << ',';
            ofs << it->second.total_sales;
            ofs << endl;
        }
    ofs.close();
}

// прочитать данные клиентов из локальной бд
void cust_table::read_data() {
    std::ifstream ifs;
    std::string line;
    ifs.open(cust_table::filename,ios::in);
    while (std::getline(ifs,line)) {
        std::stringstream ss(line);
        std::string id,name,city,state,last_visit,total_sales;

        std::getline(ss,id,',');
        std::getline(ss,name,',');
        std::getline(ss,city,',');
        std::getline(ss,state,',');
        std::getline(ss,last_visit,',');
        std::getline(ss,total_sales,',');
        
        customer cust(std::stoi(id),name,std::stoi(last_visit),std::stoi(total_sales),city,state);
        cust_table::insert_row(std::stoi(id),cust);
    }
}

// получить общие продажи всех клиентов
int cust_table::get_total_sales() {
    int total_sales_all = 0;
    for (auto it = hashtable.begin(); it != hashtable.end(); ++it) {
        total_sales_all += it->second.total_sales;
    }
    return total_sales_all;
}