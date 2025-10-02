#include <iostream>

using namespace std;

void bubble_sort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++){
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
} //O(n^2)

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
} //O(n^2)

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int index = i;
        int newNum = a[i];
        while (index > 0 && a[index - 1] > newNum) {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = newNum;
    }
} //O(n^2)

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    insertion_sort(a, n);
    //bubble_sort(a, n);
    //selection_sort(a,n);

    int x;
    cin >> x;

    bool found = false;
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (a[mid] == x) {
            cout << "Phan tu nay co trong mang" << endl;
            found = true;
            break;
        }
        else if (x > a[mid]){
            l = mid +1;
        }
        else {
            r = mid -1;
        }
    }
    if (!found) {
        cout << "Phan tu nay khong co trong mang" << endl;
    }
    return 0;
}
