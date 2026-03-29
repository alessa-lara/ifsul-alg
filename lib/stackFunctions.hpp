#ifndef STACK_FUNCTIONS
#define STACK_FUNCTIONS

#include "stack.hpp"

#include <iostream>
#include <string>

bool balancedParenthesesString(std::string expression) {
    Stack<char> stack(expression.size());

    for (char c : expression) {
        if (c == '(') {
            push(stack, c);
            continue;
        }

        if (c == ')') {
            if (isEmpty(stack)) {
                return false;
            }

            pop(stack);
        }
    }

    deleteStack(stack);

    return true;
}

template <typename T>
bool searchWithAux(Stack<T>* stack, T value) {
    Stack<T> aux;
    int size = stack->size;
    newStack(&aux, size);

    bool found = false;
    for (int i = stack->top; i > stack->bottom; i--) {
        push(&aux, pop(stack));
        if (peek(&aux) == value) {
            found = true;
        }
    }

    for (int i = stack->top; i > stack->bottom; i--) {
        push(stack, pop(&aux));
    }

    deleteStack(aux);

    return found;
}

// Searches a value inside of a inner structure
bool search(Stack<Inner>* stack, Inner value) {
    for (int i = stack->top; i > stack->bottom; i--) {
        if (value.id == stack->data[i].id) {
            return true;
        }
    }
    return false;
}

// Shows the values inside of every struct on the stack
void show(Stack<Inner>* stack) {
    for (int i = stack->top; i > stack->bottom; i--) {
        std::cout << "id: " << stack->data[i].id << ", ";
    }
}

template <typename T>
bool areEqual(Stack<T>& stack, Stack<T>& compStack) {
    if (stack.size != compStack.size)
        return false;

    Stack<T> aux(stack.size);

    bool equal = true;
    for (int i = stack.top; i > stack.bottom; i--) {
        int val = pop(compStack);
        push(aux, val);

        if (!search(stack, val)) {
            equal = false;
            break;
        }
    }

    for (int i = aux.top; i > aux.bottom; i--)
        push(compStack, pop(aux));

    deleteStack(aux);

    return equal;
}

template <typename T>
void reverseStack(Stack<T>& stack) {
    Stack<T> auxFirst(stack.top + 1);
    Stack<T> auxSec(stack.top + 1);

    for (int i = stack.top; i > stack.bottom; i--)
        push(auxFirst, pop(stack));

    for (int i = auxFirst.top; i > auxFirst.bottom; i--)
        push(auxSec, pop(auxFirst));

    for (int i = auxSec.top; i > auxSec.bottom; i--)
        push(stack, pop(auxSec));
}

template <typename T>
void copyStack(Stack<T>& stackFirst, Stack<T>& stackSec) {
    Stack<T> auxFirst(stackFirst.top + 1);
    Stack<T> auxSec(stackFirst.top + 1);

    for (int i = stackFirst.top; i > stackFirst.bottom; i--) {
        T val = pop(stackFirst);
        push(auxFirst, val);
        push(auxSec, val);
    }

    for (int i = auxFirst.top; i > auxFirst.bottom; i--) {
        push(stackFirst, pop(auxFirst));
        push(stackSec, pop(auxSec));
    }
}

#endif