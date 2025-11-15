//
// Created by 易治行 on 2025/11/15.
//

#include "LinkedList.h"

void crossRepresentation();
void triRepresentation();


int main(void) {
    crossRepresentation();
    triRepresentation();

    return 0;
}


void crossRepresentation() {
    LinkedList<char>* crossLinkedList = new LinkedList<char>();
    auto a = new CrossNode<char>(0, 0, 'a');
    auto b = new CrossNode<char>(0, 4, 'b');
    auto c = new CrossNode<char>(1, 0, 'c');
    auto d = new CrossNode<char>(1, 1, 'd');
    auto e = new CrossNode<char>(1, 5, 'e');
    auto f = new CrossNode<char>(2, 2, 'f');
    auto g = new CrossNode<char>(2, 4, 'g');
    auto h = new CrossNode<char>(3, 1, 'h');
    auto i = new CrossNode<char>(3, 4, 'i');
    auto j = new CrossNode<char>(3, 5, 'j');
    auto k = new CrossNode<char>(5, 0, 'k');
    auto l = new CrossNode<char>(5, 2, 'l');
    auto m = new CrossNode<char>(5, 4, 'm');

    a->addRight(b);
    a->addDown(d);
    b->addDown(g);
    c->addRight(d);
    c->addDown(k);
    d->addRight(e);
    d->addDown(h);
    e->addDown(j);
    f->addRight(g);
    f->addDown(l);
    g->addDown(i);
    h->addRight(i);
    i->addRight(j);
    i->addDown(m);
    k->addRight(l);
    l->addRight(m);

    crossLinkedList->append(a);
    crossLinkedList->append(b);
    crossLinkedList->append(c);
    crossLinkedList->append(d);
    crossLinkedList->append(e);
    crossLinkedList->append(f);
    crossLinkedList->append(g);
    crossLinkedList->append(h);
    crossLinkedList->append(i);
    crossLinkedList->append(j);
    crossLinkedList->append(k);
    crossLinkedList->append(l);
    crossLinkedList->append(m);

    int size = crossLinkedList->size();

    std::cout << "Cross Linked List Representation:" << std::endl;

    for (int idx = 0; idx < size; idx++) {
        auto node = (CrossNode<char>*)(*crossLinkedList)[idx];
        std::cout << "(" << node->getColumn() << ", " << node->getRow() << "): " << node->getValue() << std::endl;

        if (node->getRight())
            std::cout << "right: (" << node->getRight()->getRow() << ", " << node->getRight()->getColumn() << "): " << node->getRight()->getValue() << std::endl;
        if (node->getDown())
            std::cout << "down: (" << node->getDown()->getRow() << ", " << node->getDown()->getColumn() << "): " << node->getDown()->getValue() << std::endl;

        std::cout << std::endl;
    }

    delete crossLinkedList;
}


void triRepresentation() {
    LinkedList<char>* triLinkedList = new LinkedList<char>();

    triLinkedList->append(new TriNode<char>(0, 0, 'a'));
    triLinkedList->append(new TriNode<char>(0, 4, 'b'));
    triLinkedList->append(new TriNode<char>(1, 0, 'c'));
    triLinkedList->append(new TriNode<char>(1, 1, 'd'));
    triLinkedList->append(new TriNode<char>(1, 5, 'e'));
    triLinkedList->append(new TriNode<char>(2, 2, 'f'));
    triLinkedList->append(new TriNode<char>(2, 4, 'g'));
    triLinkedList->append(new TriNode<char>(3, 1, 'h'));
    triLinkedList->append(new TriNode<char>(3, 4, 'i'));
    triLinkedList->append(new TriNode<char>(3, 5, 'j'));
    triLinkedList->append(new TriNode<char>(5, 0, 'k'));
    triLinkedList->append(new TriNode<char>(5, 2, 'l'));
    triLinkedList->append(new TriNode<char>(5, 4, 'm'));

    std::cout << "Tri-Array Representation:" << std::endl;

    for (int idx = 0; idx < triLinkedList->size(); idx++) {
        auto node = (TriNode<char>*)(*triLinkedList)[idx];
        std::cout << "(" << node->getColumn() << ", " << node->getRow() << "): " << node->getValue() << std::endl;
    }

    delete triLinkedList;
}
