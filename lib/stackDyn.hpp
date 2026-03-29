#ifndef STACK_DYN
#define STACK_DYN

#include <iostream>
#include <stdexcept>
template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
struct Stack {
    Node<T>* top;

    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty(*this))
            pop(*this);
    }
};

template <typename T>
<<<<<<< HEAD
void deleteStack(Stack<T>& stack) {
    while ( !isEmpty(stack) ) {
        pop(stack);
    }
}

template <typename T>
bool isEmpty(Stack<T>& stack) {
    if ( stack.top == nullptr ) {
=======
bool isEmpty(Stack<T>& stack) {
    if (stack.top == nullptr) {
>>>>>>> 4652455 ([feat](stackFunctions) reverse, copy and isEqual functions)
        return true;
    }

    return false;
}

template <typename T>
void push(Stack<T>& stack, T val) {
    Node<T>* node = new Node<T>;
    node->data = val;
    node->next = stack.top;
    stack.top = node;
}

template <typename T>
T pop(Stack<T>& stack) {
<<<<<<< HEAD
    if ( isEmpty(stack) ) {
=======
    if (isEmpty(stack)) {
>>>>>>> 4652455 ([feat](stackFunctions) reverse, copy and isEqual functions)
        throw std::runtime_error("Stack vazia");
    }

    T data;
    data = stack.top->data;
    Node<T>* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;

    return data;
}

template <typename T>
T peek(Stack<T>& stack) {
    T data;

    if ( isEmpty(stack) ) {
        throw std::runtime_error("Stack vazia");
    }

    data = stack.top->data;

    return data;
}

template <typename T>
bool search(Stack<T>& stack, T value) {
    Node<T>* node = stack.top;

<<<<<<< HEAD
    while ( node != nullptr ) {
        if ( node->data == value ) {
=======
    while (node != nullptr) {
        if (node->data == value) {
>>>>>>> 4652455 ([feat](stackFunctions) reverse, copy and isEqual functions)
            return true;
        }

        node = node->next;
    }

    return false;
}

template <typename T>
void show(Stack<T>& stack) {
<<<<<<< HEAD
    if ( isEmpty(stack) ) {
        std::cout << "Stack vazia";
        return;
    }

    Node<T>* node = stack.top;

    while ( node != nullptr ) {
=======
    Node<T>* node = stack.top;

    while (node != nullptr) {
>>>>>>> 4652455 ([feat](stackFunctions) reverse, copy and isEqual functions)
        std::cout << node->data << ", ";
        node = node->next;
    }
}

#endif
