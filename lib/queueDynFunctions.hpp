#include "queueDyn.h"
#include "stackDyn.hpp"

template <typename T>
void invert(Queue<T>& queue) {
    Stack<T> stack;

    while (! isEmpty(queue))
        push(stack, dequeue(queue));

    while (! isEmpty(stack))
        enqueue(queue, pop(stack));
}

template<typename T>
Queue<T> concatenate(Queue<T>& queueFirst, Queue<T>& queueSecond) {
    Queue<T> queueConcat();

    while (! isEmpty(queueFirst))
        enqueue(queueConcat, dequeue(queueFirst));

    while (! isEmpty(queueSecond))
        enqueue(queueConcat, dequeue(queueSecond));

    return queueConcat;
}

template<typename T>
Queue<T> split(Queue<T> queue, T val) {
    Queue<T> subQueue();
    Queue<T> aux();

    bool found = false;
    while (! isempty(queue) && !found) {
        T deqVal = dequeue(queue);
        if (deqVal == val)
            break;

        enqueue(aux, deqVal);
    }

    while (! isEmpty(queue))
        enqueue(subQueue, dequeue(queue));

    return subQueue;
}
