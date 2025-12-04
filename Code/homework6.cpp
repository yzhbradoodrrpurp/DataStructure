//
// Created by 易治行 on 2025/12/4.
//

#include "Graph.h"


int main(void) {
    AdjacentMatrix* graph1 = new AdjacentMatrix(6);

    (*graph1)[0][1] = 4;
    (*graph1)[0][2] = 7;
    (*graph1)[0][5] = 8;

    (*graph1)[1][0] = 4;
    (*graph1)[1][2] = 5;

    (*graph1)[2][0] = 7;
    (*graph1)[2][1] = 5;
    (*graph1)[2][4] = 2;

    (*graph1)[3][4] = 9;

    (*graph1)[4][2] = 2;
    (*graph1)[4][3] = 9;

    (*graph1)[5][0] = 8;

    graph1->show();
    std::cout << std::endl;

    graph1->BreadthFirstSearch();
    std::cout << std::endl;
    graph1->DepthFirstSearch();
    std::cout << std::endl;

    AdjacentMatrix* mst1 = graph1->PrimMST();
    mst1->show();
    std::cout << std::endl;

    AdjacentMatrix* mst2 = graph1->KruskalMST();
    mst2->show();
    std::cout << std::endl;


    delete mst1;
    delete mst2;
    delete graph1;

    return 0;
}
