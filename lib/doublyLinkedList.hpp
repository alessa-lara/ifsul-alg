#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node() {
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T>
struct List {
    Node<T>* start;
    Node<T>* end;
    int size;

    List() {
        this->start = nullptr;
        this->end = nullptr;
        this->size = 0;
    }

    ~List() {
        Node<T>* node = this->start;

        while ( node != nullptr ) {
            Node<T>* aux = node;
            node = node->next;
            delete aux;
        }

        this->start = nullptr;
        this->end = nullptr;
        this->size = 0;
    }
};

template <typename T>
bool isEmpty(List<T>& list) {
    if ( list.start == nullptr )
        return true;

    return false;
}

template <typename T>
void show(List<T>* list) {
    Node<T>* node = list->start;

    while ( node != nullptr ) {
        std::cout << node->data;
        node = node->next;

        if ( node != nullptr )
            std::cout << ", ";
    }
}

template <typename T>
void showInverse(List<T>* list) {
    Node<T>* node = list->end;

    while ( node != nullptr ) {
        std::cout << node->data;
        node = node->prev;

        if ( node != nullptr )
            std::cout << ", ";
    }
}

template <typename T>
void insertStart(List<T>& list, T val) {
    Node<T>* newNode = new Node<T>;

    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = list.start;

    if ( list.end == nullptr )
        list.end = newNode;
    else
        list.start->prev = newNode;

    list.start = newNode;
    list.size++;
}

template <typename T>
Node<T>* search(List<T>& list, T val) {
    Node<T>* node = list.start;

    while ( node != nullptr ) {
        if ( node->data == val )
            return node;

        node = node->next;
    }

    return nullptr; // nn queria retornar nullptr
}

template <typename T>
bool removeFromList(List<T>& list, Node<T>* node) {
    if ( isEmpty(list) )
        return false;

    if ( node->prev == nullptr )
        list.start = node->next;
    else
        node->prev->next = node->next;

    // foi removido o inicio?
    if ( list.start == nullptr )
        list.end == nullptr;
    else
        list.start->prev = nullptr;

    // foi removido o fim?
    if ( node->next == nullptr )
        list.end = node->prev;
    else
        node->next->prev = node->prev;

    list.size--;
    delete node;
    return true;
}

template <typename T>
bool removeFromList(List<T>& list, T val) {
    Node<T>* node = search(list, val);

    removeFromList(list, node);

    return true;
}

#endif
