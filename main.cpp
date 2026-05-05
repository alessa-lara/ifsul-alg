// Main file primarily used to test my lib

#include "lib/queueDyn.hpp"
#include "lib/stackDyn.hpp"
#include <stdexcept>

using namespace std;

void testQueue() {
    cout << "=== TEST DYNAMIC QUEUE ===" << endl;
    Queue<int> q;
    cout << "isempty: " << isEmpty(q) << endl;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    cout << "isempty: " << isEmpty(q) << endl;
    cout << "peek: " << peek(q) << endl;
    cout << "show: ";
    show(q);
    cout << "search: " << search(q, 1) << endl;
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    cout << "show: ";
    show(q);

    try {
        dequeue(q);
    } catch ( runtime_error ) {
        cout << "caught dequeue" << endl;
    }

    try {
        peek(q);
    } catch ( runtime_error ) {
        cout << "caught peek" << endl;
    }
}

void testStack() {
    cout << "=== TEST DYNAMIC STACK ===" << endl;
    Stack<int> s;
    cout << "isempty: " << isEmpty(s) << endl;
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    cout << "isempty: " << isEmpty(s) << endl;
    cout << "peek: " << peek(s) << endl;
    cout << "show: ";
    show(s);
    cout << endl
         << "search: " << search(s, 1) << endl;
    cout << "pop: " << pop(s) << endl;
    cout << "pop: " << pop(s) << endl;
    cout << "pop: " << pop(s) << endl;
    cout << "pop: " << pop(s) << endl;
    cout << "show: ";
    show(s);

    try {
        pop(s);
    } catch ( runtime_error ) {
        cout << endl
             << "caught dequeue" << endl;
    }

    try {
        peek(s);
    } catch ( runtime_error ) {
        cout << "caught peek";
    }
}

int main() {
    testQueue();
    cout << endl;
    testStack();
}
