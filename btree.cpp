#include "lib/btree.hpp"
#include <iostream>

int main() {
    Binary_Tree<int> t = Binary_Tree<int>();
    t.insert(8, t.root);
    t.insert(2, t.root);
    t.insert(9, t.root);
    t.insert(3, t.root);
    t.insert(1, t.root);

    t.in_order(t.root);

    t.search(1, t.root);
    t.remove(1, t.root);

    std::cout << "\n";
    t.in_order(t.root);
}
