#ifndef BTREE
#define BTREE

#include "iostream"
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data, Node<T>* left = nullptr, Node<T>* right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
struct Binary_Tree {
    Node<T>* root;

    Binary_Tree(Node<T>* root = nullptr) {
        this->root = root;
    }

    Node<T>* insert(T val, Node<T>*& current) {
        if ( this->root == nullptr ) {
            this->root = new Node<T>(val);
            return nullptr;
        }

        if ( current == nullptr )
            return new Node<T>(val);

        if ( val < current->data )
            current->left = insert(val, current->left);
        else if ( val >= current->data )
            current->right = insert(val, current->right);

        return current;
    }

    void in_order(Node<T>* node) {
        if ( node == nullptr )
            return;

        cout << "<<";
        in_order(node->left);
        cout << ">>";
        cout << "<<" << node->data << ">>";
        cout << "<<";
        in_order(node->right);
        cout << ">>";
    }

    void pre_order(Node<T>*& node) {
        if ( node == nullptr )
            return;

        cout << "<<" << node->data << ">>";
        cout << "<<";
        pre_order(node->left);
        cout << ">><<";
        pre_order(node->right);
        cout << ">>";
    }

    void post_order(Node<T>*& node) {
        if ( node == nullptr )
            return;

        cout << "<<";
        post_order(node->left);
        cout << ">><<";
        post_order(node->right);
        cout << ">>";
        cout << "<<" << node->data << ">>";
    }

    bool search(T value, Node<T>* node) {
        if ( this->root == nullptr )
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            search(value, node->left);
        else
            search(value, node->right);
    }
};

#endif
