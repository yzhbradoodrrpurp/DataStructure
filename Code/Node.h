//
// Created by 易治行 on 2025/10/16.
//

#ifndef NODE_H
#define NODE_H

template<typename T>
class LinkedList;

template<typename T>
class LinkedStack;

template<typename T>
class LinkedQueue;

class Polynomial;

template<typename T>

class Node {
protected:
    T value;
    Node<T>* next;

public:
    // 使用 T() 作为默认值，避免对非指针类型使用 nullptr
    Node(T value = T(), Node<T>* next = nullptr): value(value), next(next) {}

    // 不在节点析构时递归删除 next，由链表统一管理节点生命周期
    virtual ~Node() = default;

    virtual T getValue() {
        return value;
    }

    friend class LinkedList<T>;
    friend class LinkedStack<T>;
    friend class LinkedQueue<T>;
};


template<typename T>

class TriNode: public Node<T> {
protected:
    int row;
    int column;

public:
    TriNode(int column=0, int row=0, T value=T()): Node<T>(value), row(row), column(column) {}
    virtual ~TriNode() override = default;

    virtual int getRow() {
        return row;
    }

    virtual int getColumn() {
        return column;
    }

    friend class LinkedList<T>;
    friend class LinkedStack<T>;
    friend class LinkedQueue<T>;
};

template<typename T>

class CrossNode: public TriNode<T> {
protected:
    CrossNode* right;
    CrossNode* down;

public:
    CrossNode(int column, int row, T value, CrossNode* right=nullptr, CrossNode* down=nullptr): TriNode<T>(column, row, value), right(right), down(down) {}
    ~CrossNode() override = default;

    void addRight(CrossNode* newNode) {
        this->right = newNode;
    }

    void addDown(CrossNode* newNode) {
        this->down = newNode;
    }

    CrossNode* getRight() {
        return right;
    }

    CrossNode* getDown() {
        return down;
    }

    friend class LinkedList<T>;
    friend class LinkedStack<T>;
    friend class LinkedQueue<T>;
};


class Monomial {
private:
    int coefficient;
    int exponent;
    Monomial* next;

public:
    Monomial(int coefficient, int exponent, Monomial* next=nullptr): coefficient(coefficient), exponent(exponent), next(next){}

    // 同样不在析构时删除 next
    ~Monomial() = default;

    friend class Polynomial;

};
#endif //NODE_H
