#ifndef QUEUE
#define QUEUE

#include <iostream>

struct Stack{
    int size;
    int top;
    int bottom; // pode ser omitido pois ele é um valor estático para -1
    int* data;

    Stack() {
        size = 0;
        top = -1;
        bottom = -1;
        data = NULL;
    }
};
void newStack(Stack* stack, int size) {
    stack -> size = size;
    stack -> data = new int[size];
    stack -> top = -1;
    stack -> bottom = -1;
}

bool isInit(Stack* stack) {
    if (stack -> data == NULL) {
        return false;
    }

    return true;
}

bool isEmpty(Stack* stack) {
    if (stack -> top == stack -> bottom) {
        return true;
    }

    return false;
}

bool isFull(Stack* stack) {
    if (stack -> top == stack -> size - 1) {
        return true;
    }

    return false;
}

void push(Stack* stack, int val) {
    if ( !isInit(stack) ) {
        std::cout << "queue not initialized";
        return;
    }

    stack -> data[ stack -> top ] = val;
    stack -> top++;
}

int pop(Stack* stack) {
    if ( isEmpty(stack) ) {
        return 0;
    }

    int val;
    val = stack -> data[stack -> top];
    stack -> top--;
    return val;
}

void peek(Stack* stack);

#endif