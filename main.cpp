/* main.cpp
итоговый проект
простая crm система nuts n' bolts
имя: jarred glaser
класс: sdev-240
описание: это простое консольное приложение crm. см. документацию для более подробной информации.*/

#include <iostream>
#include "headers/interface.hpp"

int main() {
    // инициализировать таблицу клиентов
    cust_table table("cust_data.csv");
    // создать объект интерфейса
    interface main_menu(table);
    // запустить основной процесс интерфейса
    main_menu.show_interface();
    return 0;
}


