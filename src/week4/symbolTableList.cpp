#include <iostream>

using namespace std;

const int MAX = 1000;
struct Item {
    string key;
    int value;
};

struct SymbolTableList {
    Item arr[MAX];
    int size;

    SymbolTableList() {
        size = 0;
    }

    int binarySearch(string key) {
        int l = 0;
        int r = size - 1;
        
        while (l<= r) {
            int mid = (l+r)/2;
            if (arr[mid].key == key) {
                return arr[mid].value;
            }
            else if (arr[mid].key < key) {
                l = mid + 1;
            }
            else {
                r = mid -1;
            }
        }
        return -1;
    }

    //thêm key vào đúng vị trí để mảng luôn sắp xếp theo key
    void put(string key, int value) {
        int i = size - 1;
        while (i >= 0 && arr[i].key > key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1].key = key;
        arr[i+1].value = value;
        size++;
    }

    //lấy giá trị theo key
    int get(string key) {
        return binarySearch(key);
    }

    //Trả về key nhỏ nhất
    string min() {
        if (size == 0) return "";
        return arr[0].key;
    }

    //trả về key lớn nhất
    string max() {
        if (size == 0) return "";
        return arr[size - 1].key;
    }

    //key lớn nhất <= key cho trước
    string floor(string key) {
        string result = "";
        for (int i = 0; i < size; i++) {
            if (arr[i].key <= key) {
                result = arr[i].key;
            }
            else {
                break;
            }
        }
        return result;
    }

    //key nhỏ nhất >= key cho trước
    string ceiling(string key) {
        string result = "";
        for (int i = 0; i < size; i++) {
            if (arr[i].key >= key) {
                result = arr[i].key;
                return result;
            }
        }
        return "";
    }

    //số key nhỏ hơn key cho trước
    int rank(string key) {
        int count = 0;
        for (int i=0; i < size; i++) {
            if (arr[i].key < key){
                count++;
            }
        }
        return count;
    }

    //trả về key có thứ hạng k
    string select(int k) {
        if (k < 0 || k > size) return "";
        return arr[k].key;
    }

    //xóa key nhỏ nhất
    void deleteMin() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }

    //xóa key lớn nhất
    void deleteMax() {
        if (size == 0) {
            return;
        }
        size--;
    }

    //đếm số key nằm giữa lo và hi
    int Size(string lo, string hi) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i].key > lo && arr[i].key < hi){
                count ++;
            }
        }
        return count;
    }

    //in ra toàn bộ key theo thứ tự
    void keys() {
        for (int i=0; i < size; i++) {
            cout << arr[i].key << " ";
        }
        cout << endl;
    }

    //in ra các key nằm giữa lo và hi
    void keys(string lo, string hi) {
        for (int i = 0; i < size; i++) {
            if (arr[i].key > lo && arr[i].key < hi){
                cout << arr[i].key << " ";
            }
        }
        cout << endl;
    }

};
