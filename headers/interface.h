/* класс интерфейса
обрабатывает интерфейс таблицы и пользовательские вводы */

#include <iostream>
#include "cust_table.h"

class interface {
    public:
        // указатель на таблицу клиентов (все действия ввода повлияют на эту таблицу)
        cust_table& customer_table;

        interface(cust_table& i_cust_table)
            : customer_table(i_cust_table)
        {};

        void show_interface();
        void show_options();
        void handle_add_cust();
        void handle_update_cust();
        void handle_delete_cust();
};