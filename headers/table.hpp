/* table.hpp
определения функций-членов класса таблицы */
#include "table.h"

// класс для добавления новой строки в таблицу
template <typename K, typename V>
void table<K,V>::insert_row(K key, V value) {
    hashtable.emplace(key,value);
}
