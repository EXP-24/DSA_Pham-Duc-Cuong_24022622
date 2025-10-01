#include <iostream>
#include "list.cpp"
#include "LinkList.cpp"

using namespace std;

struct queue_List {
    List arr;

    bool isEmpty() {
        if (arr.size == 0){
            return true;
        }
        return false;
    }

    void enqueue(int item) {
        arr.addLast(item);
    } //O(1)

    int dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        int temp = arr.get(0);
        arr.deleteFirst();
        return temp;
    } //o(n)

    int Size() {
        return arr.size;
    } //O(1)

    int top() {
        return arr.get(0);
    } //O(1)

    void print() {
        arr.traverseForward();
    } //O(n)
};

struct queue_linkedList {
    linkedList q;

    bool isEmpty() {
        if (q.head == nullptr){
            return true;
        }
        return false;
    } //O(1)

    void enqueue(int item) {
        q.addLast(item);
    } //O(1)

    int dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        int temp = q.get(0);
        q.deleteFirst();
        return temp;
    } //O(1)

    int Size() {
        return q.Count();
    } //O(n)

    int top() {
        return q.get(0);
    } //O(1)

    void print() {
        q.traverseForward();
    } //O(n)
};
