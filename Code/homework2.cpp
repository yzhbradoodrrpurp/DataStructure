//
// Created by 易治行 on 2025/10/23.
//

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


void testStack();
bool bracketMatch(std::string s);
void testQueue();
void mazeProblem();

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

void mazeProblem() {
    int m, n;
    std::cout << "Enter the size of the maze (m, n)" << std::endl;
    std::cout << "m: ";
    std::cin >> m;
    std::cout << "n: ";
    std::cin >> n;

    int maze[m][n];
    bool randomGenerated;

    std::cout << "Do you want to generate the maze randomly, (1 for yes, 0 for no): ";
    std::cin >> randomGenerated;

    if (randomGenerated) {
        srand(time(0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                maze[i][j] = rand() % 2;
        }

    }
    else {
        std::cout << "Enter the maze row by row, using 0 for open path and 1 for wall: " << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                std::cin >> maze[i][j];
        }
    }

    std::cout << "The maze is: " << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            std::cout << maze[i][j] << " ";
        std::cout << std::endl;
    }

    int entranceX, entranceY;
    std::cout << "Set the entrance coordinates (x y)" << std::endl;

    do {
        std::cout << "x: ";
        std::cin >> entranceX;
        std::cout << "y: ";
        std::cin >> entranceY;
    } while (entranceX >= 0 && entranceX < m && entranceY >= 0 && entranceY < n);

    int exitX, exitY;
    std::cout << "Set the entrance coordinates (x y)" << std::endl;

    do {
        std::cout << "x: ";
        std::cin >> exitX;
        std::cout << "y: ";
        std::cin >> exitY;
    } while (exitX >= 0 && exitX < m && exitY >= 0 && exitY < n);





}
