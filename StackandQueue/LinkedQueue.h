//
// Created by 易治行 on 2025/10/23.
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "../LinkedList/LinkedList.h"
#include "LinkedStack.h"

template<class T>

class LinkedQueue: public LinkedStack<T> {
private:
    Node<T>* tail;

public:
    LinkedQueue(): LinkedStack<T>(), tail(nullptr) {}
    virtual ~LinkedQueue() override = default;

    virtual void pop() override {
        if (this->length <= 0)
            throw std::out_of_range("pop: queue is already empty");

        if (this->length == 1) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->length -= 1;
        }
        else {
            Node<T>* p = this->head;
            this->head = this->head->next;
            delete p;
            this->length -= 1;
        }
    }

    virtual void push(Node<T>* newNode) override {
        if (this->length == 0) {
            newNode->next = nullptr;
            this->head = newNode;
            this->tail = newNode;
            this->length += 1;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
            this->length += 1;
        }
    }

};

#endif //LINKEDQUEUE_H
