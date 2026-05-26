#include "lib/doublyLinkedList.hpp"
#include <iostream>
using namespace std;

int main() {
    List<int> l;

    insertStart(l, 1);
    insertStart(l, 2);
    insertStart(l, 3);
    insertStart(l, 4);

    show(&l);
    cout << endl;

    showInverse(&l);
    cout << endl;

    cout << l.start << endl;
    cout << l.end << endl;

    if ( search(l, 1) != nullptr )
        cout << "ENCONTRAMOS o valor 1" << endl;
    else
        cout << "NAO encontramos o valor 1" << endl;

    if ( removeFromList(l, 1) )
        cout << "REMOVEMOS o valor 1" << endl;
    else
        cout << "NAO removemos o valor 1" << endl;

    show(&l);
    cout << endl;

    showInverse(&l);
    cout << endl;

    cout << l.start << endl;
    cout << l.end << endl;

    removeFromList(l, 2);
    removeFromList(l, 3);
    removeFromList(l, 4);

    show(&l);
    cout << endl;

    showInverse(&l);
    cout << endl;

    cout << l.start << endl;
    cout << l.end << endl;

    return 0;
}
