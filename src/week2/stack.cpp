#include <iostream>
#include "list.cpp"
#include "LinkList.cpp"

using namespace std;

struct stack_List {
    List arr;

    bool isEmpty() {
        if (arr.size == 0) {
            return true;
        }
        return false;
    } //O(1)

    void push(int item) {
        arr.addLast(item);
    } //O(1)

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        int value = arr.get(arr.size - 1);
        arr.deleteLast();
        return value;
    } //O(1)

    int Size() {
        return arr.size;
    } //O(1)

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return arr.get(arr.size - 1);
    } //O(1)

    void print() {
        arr.traverseForward();
    } //O(n)
};

struct stack_linkedList {
    linkedList s;

    bool isEmpty() {
        if (s.head == nullptr) {
            return true;
        }
        return false;
    } //O(1)

    void push(int item) {
        s.addFirst(item);
    } //O(1)

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        int temp = s.get(0);
        s.deleteFirst();
        return temp;
    } //O(1)

    int Size() {
        return s.Count();
    } //O(n)

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return s.get(0);
    } //O(1)

    void print() {
        s.traverseForward();
    } //O(n)
};
