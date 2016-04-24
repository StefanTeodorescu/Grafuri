//
// Created by Stefan Teodorescu on 24/04/16.
//

#ifndef GRAFURI_BINARYTREE_H
#define GRAFURI_BINARYTREE_H

#include <vector>

template <typename T>
struct Node {
    T info;
    Node *left, *right;

    Node() = default;
    Node(const T& info) : info(info), left(NULL), right(NULL) {};
};

template <typename T>
class BinaryTree {
private:
    using Node = Node<T>;
    Node *root;
    vector<T> Sorted;

    void _insert(Node *&root, const T& info) {
        if (root == NULL) {
            root = new Node(info);
            return;
        }

        if (info < root->info) {
            _insert(root->left, info);
        } else {
            _insert(root->right, info);
        }
    }

    bool _find(Node *root, const T& info) {
        if (root == NULL)
            return false;

        if (root->info == info)
            return true;

        if (info < root->info) {
            return _find(root->left, info);
        } else {
            return _find(root->right, info);
        }
    }

    void _delete(Node *root) {
        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) {
            delete root;
            return;
        }

        if (root->left != NULL) {
            _delete(root->left);
        }
        if (root->right != NULL) {
            _delete(root->right);
        }
    }

    void _copy(Node *root) {
        this->insert(root->info);
        if (root->left != NULL) {
            _copy(root->left);
        }
        if (root->right != NULL) {
            _copy(root->right);
        }
    }

    void _inOrder(Node *root) {
        if (root != NULL) {
            _inOrder(root->left);
            Sorted.push_back(root->info);
            _inOrder(root->right);
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

    ~BinaryTree() {
        _delete(root);
    }

    BinaryTree(const BinaryTree& other) {
        _delete(root);
        _copy(other.root);
    }

    void insert(const T& info) {
        _insert(root, info);
    }

    bool find(const T& info) {
        return _find(root, info);
    }

    vector<T> inOrder() {
        Sorted.clear();
        _inOrder(root);
        return Sorted;
    }
};

#endif //GRAFURI_BINARYTREE_H
