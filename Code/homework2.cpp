//
// Created by 易治行 on 2025/10/23.
//

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <string>
#include <iostream>

void testStack();
bool bracketMatch(std::string s);
void testQueue();

int main(void) {
    testStack();

    std::string b1 = "({}[])[{[()]}]";
    std::cout << b1 << ": " << bracketMatch(b1) << std::endl;
    std::string b2 = "[({[{]}})]";
    std::cout << b2 << ": " << bracketMatch(b2) << std::endl;

    testQueue();

    return 0;
}

void testStack() {
    LinkedStack<char>* s = new LinkedStack<char>();
    s->push(new Node<char>('a'));
    s->push(new Node<char>('b'));
    s->push(new Node<char>('c'));
    s->showAll();

    s->pop();
    s->showAll();
    s->pop();
    s->showAll();
    s->pop();
    s->showAll();

    delete s;
}

bool bracketMatch(std::string s) {
    LinkedStack<char>* stack = new LinkedStack<char>();
    bool isValid = true;

    for (auto ch: s) {
        if (ch == '(' || ch == '[' || ch == '{')
            stack->push(new Node<char>(ch));
        else if (ch == ')') {
            Node<char>* head = stack->headNode();
            char topValue = head->getValue();

            if (topValue == '(')
                stack->pop();
            else {
                isValid = false;
                break;
            }
        }
        else if (ch == ']') {
            Node<char>* head = stack->headNode();
            char topValue = head->getValue();

            if (topValue == '[')
                stack->pop();
            else {
                isValid = false;
                break;
            }
        }
        else if (ch == '}') {
            Node<char>* head = stack->headNode();
            char topValue = head->getValue();

            if (topValue == '{')
                stack->pop();
            else {
                isValid = false;
                break;
            }
        }
    }

    delete stack;

    return isValid;
}

void testQueue() {
    LinkedQueue<int>* q = new LinkedQueue<int>();
    q->push(new Node<int>(1));
    q->push(new Node<int>(2));
    q->push(new Node<int>(3));
    q->showAll();
    q->push(new Node<int>(4));
    q->push(new Node<int>(5));
    q->showAll();

    q->pop();
    q->pop();
    q->showAll();
    q->pop();
    q->pop();
    q->showAll();

    delete q;
}