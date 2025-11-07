#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Entry {
    int key = 0;
    int value = 0;
    bool isOccupied = false;
    bool isDeleted = false;
};

class HashTable {
private:
    vector<Entry> table;
    int tableSize;

    int hashFunc(int key) {
        return key % tableSize;
    }
public:
    HashTable(int size) {
        tableSize = size;
        table.resize(size);
        for (int i = 0; i < size; i++) {
            table[i].isOccupied = false;
            table[i].isDeleted = false;
        }
    }

    void insert(int key, int value) {
        int index = hashFunc(key);
        int startIndex = index;
        bool inserted = false;

        do {
            if (table[index].isOccupied && table[index].key == key) {
                table[index].value = value;
                return;
            }

            if (!table[index].isOccupied || table[index].isDeleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].isOccupied = true;
                table[index].isDeleted = false;
                inserted = true;
                break;
            }
            index = (index + 1) % tableSize;
        } while (index != startIndex);

        if (!inserted) {
            cout << "Bang day`, khong the them" << endl;
            return;
        }
    }

    int search(int key) {
        int index = hashFunc(key);
        int startIndex = index;

        do {
            if (table[index].isOccupied && table[index].key == key) {
                cout << "Tim thay key: " << key << " voi gia tri la: value = " << table[index].value << endl;
                return table[index].value;
            }
            if (!table[index].isOccupied && !table[index].isDeleted) {
                cout << "Khong tim thay key: " << key << endl;
                return INT_MIN;
            }
            index = (index + 1) % tableSize;
        } while (index != startIndex);
        return INT_MIN;
    }

    void remove(int key) {
        int index = hashFunc(key);
        int startIndex = index;
        bool deleted = false;

        do {
            if (!table[index].isOccupied && !table[index].isDeleted) {
                break;
            }
            if (table[index].isOccupied && table[index].key == key) {
                table[index].isOccupied = false;
                table[index].isDeleted = true;
                deleted = true;
                break;
            }
            index = (index + 1) % tableSize;
        } while (index != startIndex);
        if (!deleted) {
            cout << "khong xoa duoc: key " << key << endl;
        }
    }

    void print() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied) {
                cout << table[i].key << ", " << table[i].value;
            }
            else if (table[i].isDeleted) {
                cout << "deleted";
            }
            else {
                cout << "empty";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cin >> size;
    HashTable ht(size);
    ht.insert(20, 2);
    ht.insert(32, 12);
    ht.insert(13, 40);
    ht.insert(15, 22);
    ht.remove(32);
    ht.insert(22, 10);
    ht.search(13);
    ht.search(31);

    ht.print();
}
