#include <iostream>

//#include "stack.cpp"
#include "queue.cpp"
using namespace std;

int main() {
    /*
    stack_linkedList arr;
    arr.push(10);
    arr.push(5);
    arr.push(90);
    arr.push(43);
    int temp = arr.Size();
    cout << temp << endl;
    int n = arr.top();
    cout << n << endl;
    arr.print();
    */

    queue_linkedList arr;
    arr.enqueue(20);
    arr.enqueue(7);
    arr.enqueue(53);
    arr.enqueue(15);
    arr.enqueue(81);
    arr.dequeue();
    int s = arr.Size();
    cout << s << endl;
    int temp = arr.top();
    cout << temp << endl;
    arr.print();

    return 0;
}
