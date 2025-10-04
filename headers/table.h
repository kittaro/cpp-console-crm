/* table.h
файл заголовка класса таблицы.
используется как базовый класс таблицы, который наследует клиент */

// избежать повторной загрузки файла
#ifndef __table_H_INCLUDED__
#define __table_H_INCLUDED__

#include <iostream>
#include <map>

using namespace std;

// создать как шаблон, чтобы класс можно было расширить в будущих обновлениях
template <typename K, typename V>
class table  {
    public:
        map<K,V> hashtable;

        void insert_row(K key,V value);
};

// поскольку шаблонный класс, включаем table.cpp внизу
#include "table.hpp"

#endif