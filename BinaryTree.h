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
    Node(const T& info) : info(info), left(nullptr), right(nullptr) {};
};

template <typename T>
class BinaryTree {
private:
    using Node = Node<T>;
    Node *root;
    vector<T> Sorted;

    void _insert(Node *&root, const T& info) {
        if (root == nullptr) {
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
        if (root == nullptr)
            return false;

        if (root->info == info)
            return true;

        if (info < root->info) {
            return _find(root->left, info);
        } else {
            return _find(root->right, info);
        }
    }

    void _delete(Node *now) {
        if (now == nullptr) {
            return;
        }

        _delete(now->left);
        _delete(now->right);

        delete now;
    }

    Node* _copy(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node *now = new Node(root->info);
        now->left = _copy(root->left);
        now->right = _copy(root->right);

        return now;
    }

    void _inOrder(Node *root) {
        if (root != nullptr) {
            _inOrder(root->left);
            Sorted.push_back(root->info);
            _inOrder(root->right);
        }
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    ~BinaryTree() {
        _delete(root);
    }

    BinaryTree(const BinaryTree& other) {
        root = _copy(other.root);
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
