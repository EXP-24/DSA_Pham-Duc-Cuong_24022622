#include <iostream>

using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
    Node(string k, int v, Node* n) : key(k), value(v), next(n) {}
};

struct SymbolTableLinkedList {
    Node* head;
    int n;
    SymbolTableLinkedList() {
        head = nullptr;
        n = 0;
    }


    //thêm key vào đúng vị trí để mảng luôn sắp xếp theo key
    void put(string key, int value) {
        if (head == nullptr || key < head->key) {
            head = new Node(key, value, head);
            n++;
            return;
        }

        Node* current = head;
        Node* pre = nullptr;

        while (current != nullptr && current->key < key) {
            pre = current;
            current = current->next;
        }

        if (current != nullptr && current->key == key) {
            current->value = value;
            return;
        }

        pre->next = new Node(key, value, current);
        n++;
    }


    //lấy giá trị theo key
    int get(string key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    //Trả về key nhỏ nhất
    string min() {
        if (head != nullptr) {
            return head->key;
        }
        return "";
    }

    //trả về key lớn nhất
    string max() {
        if (head == nullptr) {
            return "";
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->key;
    }

    //key lớn nhất <= key cho trước
    string floor(string key) {
        string result = "";
        Node* current = head;
        while (current){
            if (current->key <= key) {
                result = current->key;
            }
            else {
                break;
            }
            current = current->next;
        }
        return result;
    }

    //key nhỏ nhất >= key cho trước
    string ceiling(string key) {
        string result = "";
        Node* current = head;
        while (current){
            if (current->key >= key) {
                result = current->key;
                return result;
            }
            current = current->next;
        }
        return "";
    }

    //số key nhỏ hơn key cho trước
    int rank(string key) {
        int count = 0;
        Node* current = head;
        while (current) {
            if (current->key < key) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    //trả về key có thứ hạng k
    string select(int k) {
        if (k < 0 || k >= n) return "";
        Node* current = head;
        for (int i = 0; i < k; i++){
            current = current->next;
        }
        return current->key;
    }

    //xóa key nhỏ nhất
    void deleteMin() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
    }

    //xóa key lớn nhất
    void deleteMax() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            n--;
            return;
        }

        Node* curr = head;
        while (curr->next->next){
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        n--;
    }

    //đếm số key nằm giữa lo và hi
    int Size(string lo, string hi) {
        int count = 0;
        Node* current = head;
        while (current) {
            if (current->key > lo && current->key < hi)
                count++;
            current = current->next;
        }
        return count;
    }

    //in ra toàn bộ key theo thứ tự
    void keys() {
        Node* current = head;
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    //in ra các key nằm giữa lo và hi
    void keys(string lo, string hi) {
        Node* current = head;
        while (current) {
            if (current->key > lo && current->key < hi)
                cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

};
