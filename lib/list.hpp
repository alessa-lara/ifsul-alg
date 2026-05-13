#ifndef LIST
#define LIST

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node() {
        this->next = nullptr;
    }
};

template <typename T>
bool isEmpty(Node<T>*& linkList) {
    if (linkList == nullptr)
        return true;

    return false;
}

template <typename T>
void deleteList(Node<T>*& linkList) {
    Node<T>* node = linkList;

    while (node != nullptr) {
        Node<T>* aux = node;
        node = node->next;
        delete aux;
    }

    linkList = nullptr;
}

template <typename T>
void show(Node<T>*& linkList) {
    Node<T>* node = linkList;

    while (node != nullptr) {
        std::cout << node->data;

        node = node->next;

        if (node != nullptr)
            std::cout << ", ";
    }
}

template <typename T>
bool insertStart(Node<T>*& linkList, T val) {

    Node<T>* newNode = new Node<T>;
    if (newNode == nullptr)
        return false;

    newNode->data = val;
    newNode->next = linkList;
    linkList = newNode;

    return true;
}

template <typename T>
bool insertEnd(Node<T>*& linkList, T val) {
    Node<T>* newNode = new Node<T>;
    if (newNode == nullptr)
        return false;

    newNode->data = val;
    newNode->next = nullptr;

    Node<T>* prev = nullptr;
    Node<T>* node = linkList;
    while (node != nullptr) {
        prev = node;
        node = node->next;
    }

    prev->next = newNode;

    return true;
}

template <typename T>
bool removeValue(Node<T>*& linkList, T val) {
    Node<T>* prev = nullptr;
    Node<T>* node = linkList;

    while (node != nullptr && node->data != val) {
        prev = node;
        node = node->next;
    }

    if (node == nullptr)
        return false;

    // val está no inicio da lista
    if (prev == nullptr)
        linkList = node->next;
    else
        prev->next = node->next;

    delete node;

    return true;
}

template <typename T>
bool search(Node<T>*& linkList, T val) {
    Node<T>* node = linkList;

    while (node != nullptr) {
        if (node->data == val)
            return true;

        node = node->next;
    }

    return false;
}

#endif
