#ifndef STACK
#define STACK

#include <iostream>

struct Inner {
    int id;
};

template<typename T>
struct Stack {
    int size;
    int top;
    int bottom; // pode ser omitido pois ele é um valor estático para -1
    T* data;

    Stack() {
        size = 0;
        top = -1;
        bottom = -1;
        data = NULL;
    }
};

template<typename T>
void newStack(Stack<T>* stack, int len) {
    stack->size = len;
    stack->data = new int[len];
    stack->top = -1;
    stack->bottom = -1;
}

template<typename T>
void deleteStack(Stack<T>* stack) {
    stack->size = 0;
    delete[] stack->data;
    stack->data = nullptr;
    stack->top = -1;
    stack->bottom = -1;
}

template<typename T>
bool isInit(Stack<T>* stack) {
    if ( stack->data == NULL ) {
        return false;
    }

    return true;
}

template<typename T>
bool isEmpty(Stack<T>* stack) {
    if ( stack->top == stack->bottom ) {
        return true;
    }

    return false;
}

template<typename T>
bool isFull(Stack<T>* stack) {
    if ( stack->top == stack->size - 1 ) {
        return true;
    }

    return false;
}

template<typename T>
void push(Stack<T>* stack, T val) {
    stack->top++;
    stack->data[stack->top] = val;
}

template<typename T>
T pop(Stack<T>* stack) {
    T val;
    val = stack->data[stack->top];
    stack->top--;
    return val;
}

template<typename T>
T peek(Stack<T>* stack) {
    T val;
    val = stack->data[stack->top];
    return val;
}

template<typename T>
bool search(Stack<T>* stack, T value) {
    for ( int i = stack->top; i > stack->bottom; i-- ) {
        if ( value == stack->data[i] ) {
            return true;
        }
    }
    return false;
}

template<typename T>
void show(Stack<T>* stack) {
    for (int i = stack->top; i > stack-> bottom; i--) {
        std::cout << stack->data[i] << ", ";
    }
}

#endif