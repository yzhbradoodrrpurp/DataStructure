//
// Created by 易治行 on 2025/11/20.
//

#include "Tree.h"

int main(void) {
    // 构造一棵示例二叉树：
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    Tree<int>* n1 = new Tree<int>(1);
    Tree<int>* n2 = new Tree<int>(2);
    Tree<int>* n3 = new Tree<int>(3);
    Tree<int>* n4 = new Tree<int>(4);
    Tree<int>* n5 = new Tree<int>(5);
    Tree<int>* n6 = new Tree<int>(6);

    n1->addLeft(n2); n1->addRight(n3);
    n2->addLeft(n4); n2->addRight(n5);
    n3->addRight(n6);

    n1->show();

    // preorder traversal
    n1->preorderTraverse(true);
    std::cout << std::endl;
    n1->preorderTraverse(false);
    std::cout << std::endl;

    // inorder traversal
    n1->inorderTraverse(true);
    std::cout << std::endl;
    n1->inorderTraverse(false);
    std::cout << std::endl;

    // postorder traversal
    n1->postorderTraverse(true);
    std::cout << std::endl;
    n1->postorderTraverse(false);
    std::cout << std::endl;

    delete n1;

    return 0;
}