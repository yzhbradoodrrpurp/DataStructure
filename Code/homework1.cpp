//
// Created by 易治行 on 2025/10/16.
//

#include "LinkedList.h"

void LinkedListFunctionTest();
void polynomialTest();

int main(void) {
    LinkedListFunctionTest();
    polynomialTest();

    return 0;
}

void polynomialTest() {
    Polynomial* poly = new Polynomial();

    // 3x^3 + 7x^6 + 5x^3 + 4x^5 + 8x^6
    Monomial* mono1 = new Monomial(3, 3);
    poly->append(mono1);
    Monomial* mono2 = new Monomial(7, 6);
    poly->append(mono2);
    Monomial* mono3 = new Monomial(5, 3);
    poly->append(mono3);
    Monomial* mono4 = new Monomial(4, 5);
    poly->append(mono4);
    Monomial* mono5 = new Monomial(8, 6);
    poly->append(mono5);

    poly->showAll();
    Polynomial* result = poly->fuse();
    result->showAll();

    delete poly;
    delete result;
}

void LinkedListFunctionTest() {
    LinkedList<char>* list = new LinkedList<char>();

    list->append(new Node<char>('a'));
    list->append(new Node<char>('b'));
    list->insert(new Node<char>('c'), 1);
    list->insert(new Node<char>('d'), 1);
    list->insert(new Node<char>('d'), 0);

    list->showAll(); // d a d c b

    list->remove(1);
    list->remove(2);
    list->pop();

    list->showAll(); // d d

    delete list;
}