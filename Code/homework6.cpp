//
// Created by 易治行 on 2025/11/20.
//

#include "BinaryTree.h"

int main(void) {
    // 构造一棵示例二叉树：
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    BinaryTree<int>* n1 = new BinaryTree<int>(1);
    BinaryTree<int>* n2 = new BinaryTree<int>(2);
    BinaryTree<int>* n3 = new BinaryTree<int>(3);
    BinaryTree<int>* n4 = new BinaryTree<int>(4);
    BinaryTree<int>* n5 = new BinaryTree<int>(5);
    BinaryTree<int>* n6 = new BinaryTree<int>(6);

    n1->addLeft(n2); n1->addRight(n3);
    n2->addLeft(n4); n2->addRight(n5);
    n3->addRight(n6);

    n1->show();
    std::cout << std::endl;

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