//
// Created by 易治行 on 2025/12/11.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

class HashTable {
private:
    int *array;
    bool *occupied;
    int capacity;
    int length;

public:
    HashTable(int capacity): capacity(capacity) {
        array = new int[capacity];
        occupied = new bool[capacity];
        length = 0;

        for (int i = 0; i < capacity; i++)
            occupied[i] = false;
    }

    ~HashTable() {
        delete array;
        delete occupied;
    }

    void add(int item) {
        int idx = item % 13;

        while (occupied[idx])
            idx = (idx + 1) % capacity;

        array[idx] = item;
        occupied[idx] = true;
        length++;
    }

    void show() {
        for (int i = 0; i < capacity; i++) {
            if (occupied[i])
                std::cout << "[" << i << "]: " << array[i] << std::endl;
            else
                std::cout << "[" << i << "]: " << "null" << std::endl;
        }
    }

    int find(int item) {
        int startidx = item % 13;

        if (occupied[startidx] && array[startidx] == item)
            return startidx;

        int idx = (startidx + 1) % capacity;

        while (occupied[idx]) {
            if (array[idx] == item)
                return idx;
            
            idx = (idx + 1) % capacity;
        }

        return -1;
    }

    void remove(int item) {
        int idx = this->find(item);

        if (idx != -1) {
            occupied[idx] = false;
            length--;
        }
    }

};

#endif //HASHTABLE_H
