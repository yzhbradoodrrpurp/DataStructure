//
// Created by 易治行 on 2025/12/4.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <iostream>

class AdjacentMatrix {
private:
    int dimension;
    int** matrix;

public:
    AdjacentMatrix(int dimension): dimension(dimension) {
        matrix = (int**) malloc(sizeof(int*) * dimension);

        for (int i = 0; i < dimension; i++) {
            matrix[i] = (int*) malloc(sizeof(int) * dimension);

            for (int j = 0; j < dimension; j++)
                matrix[i][j] = 0;
        }
    }

    ~AdjacentMatrix() {
        for (int i = 0; i < dimension; i++)
            free(matrix[i]);

        free(matrix);
    }

    int* operator[](int idx) {
        if (idx >= dimension || idx < 0)
            throw std::out_of_range("AdjacentMatrix: index out of range");

        return matrix[idx];
    }

    void DepthFirstSearch() {
        std::vector<bool> visited(dimension, false);

        for (int i = 0; i < dimension; i++) {
            if (!visited[i]) {
                LinkedStack<int> stack;
                stack.push(new Node<int>(i));
                visited[i] = true;

                while (!stack.empty()) {
                    Node<int>* currentNode = stack.headNode();
                    int currentIndex = currentNode->getValue();
                    stack.pop();

                    std::cout << "Visited Node: " << currentIndex << std::endl;

                    for (int j = 0; j < dimension; j++) {
                        if (matrix[currentIndex][j] != 0 && !visited[j]) {
                            stack.push(new Node<int>(j));
                            visited[j] = true;
                        }
                    }
                }
            }
        }
    }

    void BreadthFirstSearch() {
        std::vector<bool> visited(dimension, false);

        for (int i = 0; i < dimension; i++) {
            if (!visited[i]) {
                LinkedQueue<int> queue;
                queue.push(new Node<int>(i));
                visited[i] = true;

                while (!queue.empty()) {
                    Node<int>* currentNode = queue.headNode();
                    int currentIndex = currentNode->getValue();
                    queue.pop();

                    std::cout << "Visited Node: " << currentIndex << std::endl;

                    for (int j = 0; j < dimension; j++) {
                        if (matrix[currentIndex][j] != 0 && !visited[j]) {
                            queue.push(new Node<int>(j));
                            visited[j] = true;
                        }
                    }
                }
            }
        }
    }
};



#endif //GRAPH_H
