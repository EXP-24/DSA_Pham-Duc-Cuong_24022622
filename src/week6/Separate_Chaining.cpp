#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    int tableSize;
    vector<Node*> table;

    int hashFunc(int key) {
        return key % tableSize;
    }

public:
    HashTable(int size) {
        tableSize = size;
        table.resize(size, nullptr);
    }

    void insert(int key, int value) {
        int index = hashFunc(key);
        Node* head = table[index];

        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void remove(int key) {
        int index = hashFunc(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while(current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Khong ton tai key: " << key << endl;
    }

    int search(int key) {
        int index = hashFunc(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                cout << "Tim thay key: " << key << " voi gia tri la: value = " << current->value << endl;
                return current->value;
            }
            current = current->next;
        }
        cout << "Khong tim thay key: " << key << endl;
        return INT_MIN;
    }

    void print() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            Node* current = table[i];
            if (current == nullptr) {
                cout << "empty";
            }
            while (current != nullptr) {
                cout << "[" << current->key << " -> " << current->value << "] ";
                current = current->next;
            }
            cout << endl;
        }
    }
};


int main() {
    int size;
    cin >> size;
    HashTable ht(size);

    ht.insert(1, 10);
    ht.insert(6, 20);
    ht.insert(11, 30);
    ht.insert(11,32);
    ht.insert(2, 40);
    ht.remove(6);
    ht.search(2);
    ht.print();

    return 0;
}

