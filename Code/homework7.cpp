//
// Created by 易治行 on 2025/12/11.
//

#include "HashTable.h"
#include <iostream>

int main(void) {
    HashTable* hashtable = new HashTable(16);

    hashtable->add(19);
    hashtable->add(14);
    hashtable->add(23);
    hashtable->add(1);
    hashtable->add(68);
    hashtable->add(20);
    hashtable->add(84);
    hashtable->add(27);
    hashtable->add(55);
    hashtable->add(11);
    hashtable->add(10);
    hashtable->add(79);

    hashtable->show();

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::vector<int> result = hashtable->find(num);
    int idx = result[0];
    int times = result[1];
    if (idx != -1)
        std::cout << "Found " << num << " at index " << idx << " after " << times << " probes." << std::endl;
    else
        std::cout << num << " not found after " << times << " probes." << std::endl;



    delete hashtable;

    return 0;
}