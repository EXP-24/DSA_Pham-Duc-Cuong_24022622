#include <iostream>
#include "list.cpp"

using namespace std;

//parent = (i-1)/2
//right = 2 * i + 2
//left = 2 * i + 1
struct priorityQueue {
    List heap;

    void swap(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }//O(1)

    void swim(int k) {
        while (k > 0 && heap.get(((k - 1) / 2)) < heap.get(k)) {
            swap(k, ((k - 1) / 2));
            k = (k-1)/2;
        }
    }//O(logn)

    void sink(int k) {
        while (2*k+1 < heap.getSize()) {
            int j = 2*k+1;
            if (j + 1 < heap.getSize() && heap.get(j) < heap.get(j+1)) {
                j++;
            }
            if (heap.get(k) >= heap.get(j)) {
                break;
            }
            swap(k, j);
            k = j;
        }
    }//O(logn)

    void insert(int data) {
        heap.addLast(data);
        swim(heap.getSize() - 1);
    }//O(logn)

    int delMax() {
        if (isEmpty()){
            cout << "Heap nay rong!" << endl;
        }
        int temp = heap.get(0);
        swap(0, heap.getSize() - 1);
        heap.deleteLast();
        sink(0);
        return temp;
    }//O(logn)

    bool isEmpty() {
        if (heap.getSize() == 0) {
            return true;
        }
        return false;
    }//O(1)

    int max() {
        int Max;
        if (isEmpty()){
            cout << "Heap nay rong!" << endl;
        }
        else {
            Max = heap.get(0);
        }
        return Max;
    }//O(1)

    int size() {
        return heap.getSize();
    }//O(1)

    void printHeap() {
        for (int i = 0; i < heap.getSize(); i++) {
            cout << heap.get(i) << " ";
        }
        cout << endl;
    }//O(n)
};
