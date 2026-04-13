#ifndef QUEUE_DYN
#define QUEUE_DYN

#include <iostream>
#include <new>
#include <stdexcept>

template <typename T>
struct NodeQueue {
    T data;
    NodeQueue* next;

    NodeQueue(T data) {
        data;
        next = nullptr;
    }
};

template <typename T>
struct Queue {
    NodeQueue<T>* head;
    NodeQueue<T>* tail;

    Queue() {
        head = nullptr;
        tail = nullptr;
    }
};

template <typename T>
bool isEmpty(Queue<T>& queue) {
    if (queue.head == nullptr)
        return true;

    return false;
}

template <typename T>
void enqueue(Queue<T>& queue, T data) {
    NodeQueue<T>* node = new NodeQueue(data);

    if (node == nullptr)
        throw std::bad_alloc();

    if (isEmpty(queue))
        queue.head = node;
    else
        queue.tail->next = node;

    queue.tail = node;
}

template <typename T>
T dequeue(Queue<T>& queue) {
    if (isEmpty(queue))
        throw std::logic_error("Queue vazia");

    T data = queue.head->data;
    NodeQueue<T>* old = queue.head;
    queue.head = queue.head->next;
    delete old;

    if (isEmpty(queue))
        queue.tail = nullptr;

    return data;
}

template <typename T>
T peek(Queue<T>& queue) {
    if (isEmpty(queue))
        throw std::logic_error("Queue vazia");

    return queue.head->data;
}

template <typename T>
void show(Queue<T>& queue) {
    if (isEmpty(queue))
        std::cout << "Queue vazia";

    NodeQueue<T>* curr = queue.head;
    while (curr != nullptr) {
        std::cout << curr->data << ", ";
        curr = curr->next;
    }
}

template <typename T>
bool search(Queue<T>& queue, T value) {
    if (isEmpty(queue))
       return false; 

    NodeQueue<T>* curr = queue.head;
    while (curr != nullptr) {
        if (curr->data == value)
            return true;
    }

    return false;
}

template <typename T>
void deleteQueue(Queue<T>& queue) {
    NodeQueue<T> curr = queue.head;
    while (curr != nullptr) {
        NodeQueue<T> old = curr;
        curr = curr->next;
        delete old;
    }
}

#endif
