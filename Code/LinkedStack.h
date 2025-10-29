//
// Created by 易治行 on 2025/10/23.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedList.h"

template<class T>

class LinkedStack: public LinkedList<T> {
public:
    LinkedStack(): LinkedList<T>(){}
    virtual ~LinkedStack() override = default;

    virtual void pop() override {
        if (this->length <= 0)
            throw std::out_of_range("pop: stack is already empty");

        if (this->length == 1) {
            delete this->head;
            this->head = nullptr;
            this->length -= 1;
        }
        else {
            Node<T>* p = this->head;
            this->head = this->head->next;
            delete p;
            this->length -= 1;
        }
    }

    virtual void push(Node<T>* newNode) {
        if (this->length == 0) {
            this->head = newNode;
            this->length += 1;
        }
        else {
            newNode->next = this->head;
            this->head = newNode;
            this->length += 1;
        }
    }

private:
    virtual void append(Node<T>*) override{}
    virtual void remove(int) override {}
    virtual void insert(Node<T>*, int) override {}

};


#endif //LINKEDSTACK_H
