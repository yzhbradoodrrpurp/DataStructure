//
// Created by 易治行 on 2025/11/20.
//

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stack>

template<typename T>

class BinaryTree {
protected:
    T value;
    BinaryTree<T>* left;
    BinaryTree<T>* right;

public:
    BinaryTree(T value=T(), BinaryTree<T>* left=nullptr, BinaryTree<T>* right=nullptr): value(value), left(left), right(right) {}

    virtual ~BinaryTree() {
        delete left;
        delete right;
    }

    T Value() {
        return value;
    }

    BinaryTree<T>* leftTree() {
        return left;
    }

    BinaryTree<T>* rightTree() {
        return right;
    }

    void addLeft(BinaryTree<T>* tree) {
        left = tree;
    }

    void addRight(BinaryTree<T>* tree) {
        right = tree;
    }

    int height() {
        int leftHeight = 0;
        int rightHeight = 0;

        if (left)
            leftHeight = left->height();

        if (right)
            rightHeight = right->height();

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }

    void show(int indent=0) {
        if (left)
            left->show(indent + 1);

        for (int i = 0; i < indent; i++)
            std::cout << "\t";
        std::cout << value << std::endl;

        if (right)
            right->show(indent + 1);
    }

    void preorderTraverse(bool recursion=true) {
        if (recursion) {
            std::cout << value << "\t";

            if (left)
                left->preorderTraverse();

            if (right)
                right->preorderTraverse();
        }
        else {
            std::stack<BinaryTree<T>*> stack;
            stack.push(this);

            while (!stack.empty()) {
                BinaryTree<T>* tree = stack.top();
                stack.pop();
                std::cout << tree->value << "\t";

                if (tree->right)
                    stack.push(tree->right);

                if (tree->left)
                    stack.push(tree->left);
            }
        }
    }

    void inorderTraverse(bool recursion=true) {
        if (recursion) {
            if (left)
                left->inorderTraverse();

            std::cout << value << "\t";

            if (right)
                right->inorderTraverse();
        }
        else {
            std::stack<BinaryTree<T>*> stack;
            BinaryTree<T>* currrent = this;

            while (currrent != nullptr || !stack.empty()) {
                while (currrent != nullptr) {
                    stack.push(currrent);
                    currrent = currrent->left;
                }

                currrent = stack.top();
                stack.pop();
                std::cout << currrent->value << "\t";
                currrent = currrent->right;
            }
        }
    }

    void postorderTraverse(bool recursion=true) {
        if (recursion) {
            if (left)
                left->postorderTraverse();

            if (right)
                right->postorderTraverse();

            std::cout << value << "\t";
        }
        else {
            std::stack<BinaryTree<T>*> s1, s2;
            s1.push(this);

            while (!s1.empty()) {
                BinaryTree<T>* node = s1.top(); s1.pop();
                s2.push(node);

                if (node->left)
                    s1.push(node->left);
                if (node->right)
                    s1.push(node->right);
            }

            while (!s2.empty()) {
                std::cout << s2.top()->value << "\t";
                s2.pop();
            }
        }
    }



};


#endif //TREE_H
