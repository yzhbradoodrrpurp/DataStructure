//
// Created by 易治行 on 2025/10/16.
//

#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include "Node.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>

class LinkedList {
protected:
    Node<T>* head;
    int length;

public:
    LinkedList(): head(nullptr), length(0) {}
    virtual ~LinkedList() {
        while (length != 0)
            if (length == 1) {
                delete head;
                head = nullptr;
                length--;
            }
            else {
                Node<T>* p = head;

                for (int i  = 0; i < length - 2; i++)
                    p = p->next;

                delete p->next;
                p->next = nullptr;

                length--;
            }
    }


    virtual void append(Node<T>* newNode) {
        newNode->next = nullptr;

        if (head == nullptr)
            head = newNode;
        else {
            Node<T>* p = head;

            while (p->next != nullptr)
                p = p->next;

            p->next = newNode;
        }

        // 防止外部传入的 newNode 带有未初始化或指向其它结构的 next
        newNode->next = nullptr;

        length++;
    }

    virtual void pop() {
        if (length == 1) {
            delete head;
            head = nullptr;
            length--;
        }
        else {
            Node<T>* p = head;

            for (int i  = 0; i < length - 2; i++)
                p = p->next;

            delete p->next;
            p->next = nullptr;

            length--;
        }
    }


    virtual void remove(int idx) {
        if (idx >= length || idx < 0)
            throw std::out_of_range("remove: index out of range");

        if (idx == 0) {
            Node<T>* removedNode = head;
            head = head->next;
            delete removedNode;

            length--;
        }
        else {
            Node<T>* p = head;

            for (int i = 0; i < idx - 1; i++)
                p = p->next;

            Node<T>* removedNode = p->next;
            p->next = removedNode->next; // 跳过被删除节点
            delete removedNode;

            length--;
        }
    }

    virtual void insert(Node<T>* newNode, int idx) {
        if (idx < 0 || idx >= length)
            throw std::out_of_range("insert: index out of range");

        if (idx == 0) {
            newNode->next = head;
            head = newNode;

            length++;
        }
        else {
            Node<T>* p = head;

            for (int i = 0; i < idx - 1; i++)
                p = p->next;

            newNode->next = p->next;
            p->next = newNode;

            length++;
        }
    }

    virtual bool empty() {
        return length == 0;
    }

    virtual int size() {
        return length;
    }

    virtual void showAll() {
        Node<T>* p = head;

        while (p != nullptr) {
            std::cout << p->value << " ";
            p = p->next;
        }

        std::cout << std::endl;
    }


    virtual void show(int idx) {
        if (idx < 0 || idx >= length)
            throw std::out_of_range("show: index out of range");

        Node<T>* p = head;

        for (int i = 0; i < idx; i++)
            p = p->next;

        std::cout << p->value << std::endl;
    }

    virtual Node<T>*& getNode(int idx) {
        if (idx < 0 || idx >= length)
            throw std::out_of_range("operator[]: index out of range");

        Node<T>* p = this->head;
        for (int i = 0; i < idx; i++)
            p = p->next;

        return p;
    }

    Node<T>*& operator[](int idx) {
        return getNode(idx);
    }

    Node<T>* headNode() {
        return head;
    }

    static LinkedList<int>* merge(const LinkedList<int>* list1, const LinkedList<int>* list2) {
        LinkedList<int>* mergedList = new LinkedList<int>();
        std::vector<int> values;

        auto p = list1->head;
        auto q = list2->head;

        while (p != nullptr) {
            int flag = 0;

            for (auto value: values) {
                if (p->value == value) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                values.push_back(p->value);

            p->next;
        }

        while (q != nullptr) {
            int flag = 0;

            for (auto value: values) {
                if (q->value == value) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                values.push_back(q->value);

            q->next;
        }

        std::sort(values.begin(), values.end(), [](int a, int b) {
            return a > b;
        });

        for (auto value: values)
            mergedList->append(new Node<int>(value));

        return mergedList;
    }
};

class Polynomial {
    Monomial* head;
    int length;

public:
    Polynomial(): head(nullptr), length(0) {}
    ~Polynomial() {
        while (length != 0)
            this->pop();
    }


    void append(Monomial* newNode) {
        if (head == nullptr)
            head = newNode;
        else {
            Monomial* p = head;

            while (p->next != nullptr)
                p = p->next;

            p->next = newNode;
        }

        // 同上：确保单项式节点的 next 被重置
        newNode->next = nullptr;

        length++;
    }

    void pop() {
        if (length == 1) {
            delete head;
            head = nullptr;
            length--;
        }
        else {
            Monomial* p = head;

            for (int i  = 0; i < length - 2; i++)
                p = p->next;

            delete p->next;
            p->next = nullptr;

            length--;
        }

    }


    void remove(int idx) {
        if (idx >= length || idx < 0)
            throw std::out_of_range("remove: index out of range");

        if (idx == 0) {
            Monomial* removedNode = head;
            head = head->next;
            delete removedNode;

            length--;
        }
        else {
            Monomial* p = head;

            for (int i = 0; i < idx - 1; i++)
                p = p->next;

            Monomial* removedNode = p->next;
            p->next = removedNode->next; // 跳过被删除节点
            delete removedNode;

            length--;
        }
    }

    void insert(Monomial* newNode, int idx) {
        if (idx < 0 || idx >= length)
            throw std::out_of_range("insert: index out of range");

        if (idx == 0) {
            newNode->next = head;
            head = newNode;

            length++;
        }
        else {
            Monomial* p = head;

            for (int i = 0; i < idx - 1; i++)
                p = p->next;

            newNode->next = p->next;
            p->next = newNode;

            length++;
        }
    }

    bool empty() {
        return length == 0;
    }

    int size() {
        return length;
    }

    void showAll() {
        Monomial* p = head;

        while (p != nullptr) {
            std::cout << p->coefficient << "x^" << p->exponent << " ";
            p = p->next;
        }

        std::cout << std::endl;
    }

    void show(int idx) {
        if (idx < 0 || idx >= length)
            throw std::out_of_range("show: index out of range");

        Monomial* p = head;

        for (int i = 0; i < idx; i++)
            p = p->next;

        std::cout << p->coefficient << "x^" << p->exponent << std::endl;
    }

    std::vector<int> allExponents() {
        std::vector<int> exponents;

        Monomial* p = head;

        while (p != nullptr) {

            int flag = 0;
            for (auto element: exponents) {
                if (p->exponent == element) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
                exponents.push_back(p->exponent);

            p = p->next;
        }

        std::sort(exponents.begin(), exponents.end(), [](int a, int b) {
            return a > b;
        });

        return exponents;
    }

    Polynomial* fuse() {
        std::vector<int> exponents = allExponents();

        Polynomial* result = new Polynomial();

        for (auto exponent: exponents) {
            int sum = 0;
            Monomial* p = head;

            while (p != nullptr) {
                if (p->exponent == exponent)
                    sum += p->coefficient;
                p = p->next;
            }

            Monomial* newNode = new Monomial(sum, exponent);
            result->append(newNode);
        }

        return result;
    }
};

#endif //SIMPLELINKEDLIST_H
