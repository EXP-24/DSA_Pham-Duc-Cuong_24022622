#include <iostream>

#include "priority_queue.cpp"
using namespace std;

int main() {

    priorityQueue h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(8);
    h.insert(50);

    h.printHeap();

    cout << h.size() << endl;
    cout << h.max() << endl;
    cout << h.delMax() << endl;
    cout << "After delMax: ";
    h.printHeap();

    return 0;
}

