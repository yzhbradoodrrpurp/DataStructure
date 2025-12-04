//
// Created by 易治行 on 2025/12/4.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include <iostream>
#include <limits>
#include <algorithm>

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

    bool bothInMST(AdjacentMatrix* mst, int idxI, int idxJ) {
        std::vector<int> inMST;

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                if ((*mst)[i][j] != 0) {
                    inMST.push_back(i);
                    inMST.push_back(j);
                }
            }
        }

        bool foundI = false;
        bool foundJ = false;

        for (int i = 0; i < inMST.size(); i++) {
            if (inMST[i] == idxI)
                foundI = true;
        }

        for (int i = 0; i < inMST.size(); i++) {
            if (inMST[i] == idxJ)
                foundJ = true;
        }

        return foundI == foundJ;
    }

    AdjacentMatrix* PrimMST() {
        // 标准 Prim 算法实现（matrix 中 0 表示无边）
        AdjacentMatrix* mst = new AdjacentMatrix(dimension);
        if (dimension <= 0) return mst;

        const int INF = std::numeric_limits<int>::max() / 4;
        std::vector<int> key(dimension, INF);
        std::vector<int> parent(dimension, -1);
        std::vector<bool> inMST(dimension, false);

        key[0] = 0; // 从顶点 0 开始

        for (int cnt = 0; cnt < dimension; ++cnt) {
            int u = -1;
            int best = INF;
            for (int v = 0; v < dimension; ++v) {
                if (!inMST[v] && key[v] < best) {
                    best = key[v];
                    u = v;
                }
            }
            if (u == -1) break; // 剩余顶点不可达
            inMST[u] = true;

            // 更新与 u 相邻的顶点
            for (int v = 0; v < dimension; ++v) {
                int w = matrix[u][v];
                if (w != 0 && !inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        // 用 parent 数组构造 mst（无向图对称赋值）
        int edgeCount = 0;
        for (int v = 0; v < dimension; ++v) {
            if (parent[v] != -1) {
                int u = parent[v];
                (*mst)[u][v] = matrix[u][v];
                (*mst)[v][u] = matrix[u][v];
                ++edgeCount;
            }
        }

        if (edgeCount != dimension - 1) {
            std::cout << "PrimMST: graph not fully connected, produced partial MST with "
                      << edgeCount << " edges." << std::endl;
        }

        return mst;
    }

    void show() {
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    AdjacentMatrix* KruskalMST() {
        AdjacentMatrix* mst = new AdjacentMatrix(dimension);
        if (dimension <= 0) return mst;

        struct Edge { int u, v, w; };
        std::vector<Edge> edges;
        edges.reserve(dimension * (dimension - 1) / 2);

        // 收集边（只取 i<j，避免重复）
        for (int i = 0; i < dimension; ++i) {
            for (int j = i + 1; j < dimension; ++j) {
                int w = matrix[i][j];
                if (w != 0) edges.push_back({i, j, w});
            }
        }

        // 按权重升序排序
        std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });

        // 并查集初始化
        std::vector<int> parent(dimension);
        std::vector<int> rank(dimension, 0);
        for (int i = 0; i < dimension; ++i) parent[i] = i;

        std::function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        auto unite = [&](int a, int b) -> bool {
            int pa = find(a), pb = find(b);
            if (pa == pb) return false;
            if (rank[pa] < rank[pb]) parent[pa] = pb;
            else if (rank[pb] < rank[pa]) parent[pb] = pa;
            else { parent[pb] = pa; rank[pa]++; }
            return true;
        };

        int added = 0;
        for (const auto &e : edges) {
            if (unite(e.u, e.v)) {
                (*mst)[e.u][e.v] = e.w;
                (*mst)[e.v][e.u] = e.w;
                if (++added == dimension - 1) break;
            }
        }

        if (added != dimension - 1) {
            std::cout << "KruskalMST: graph not fully connected, produced partial MST with "
                      << added << " edges." << std::endl;
        }

        return mst;
    }


};



#endif //GRAPH_H
