#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void merge(int arr[], int leftArr[], int rightArr[], int size) {
    int leftSize = size/2;
    int rightSize = size - leftSize;
    int i=0, l=0, r=0;

    while(l < leftSize && r < rightSize) {
        if (leftArr[l] < rightArr[r]) {
            arr[i++] = leftArr[l++];
        }
        else {
            arr[i++] = rightArr[r++];
        }
    }
    while (l < leftSize) {
        arr[i++] = leftArr[l];
        l++;
    }
    while (r < rightSize) {
        arr[i++] = rightArr[r];
        r++;
    }
}

void mergeSort (int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int* leftArr = new int[mid];
    int* rightArr = new int[size - mid];

    for (int i = 0; i < mid; i++) {
        leftArr[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        rightArr[i - mid] = arr[i];
    }
    mergeSort(leftArr, mid);
    mergeSort(rightArr, size - mid);
    merge(arr, leftArr, rightArr, size);

    delete[] leftArr;
    delete[] rightArr;
}

void quickSort(int arr[], int l, int r) {
    int i = l;
    int j = r;
    int mid = (l+r)/2;
    int pivot  = arr[mid];

    while (i < j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (i < r) {
        quickSort(arr, i, r);
    }
    if (j > l) {
        quickSort(arr, l, j);
    }
}

void heapify(int arr[], int size, int k) {
    int dinhGoc = k;
    int leftC = 2*k+1;
    int rightC = 2*k+2;

    if (leftC < size && arr[leftC] > arr[dinhGoc]){
        dinhGoc = leftC;
    }
    if (rightC < size && arr[rightC] > arr[dinhGoc]) {
        dinhGoc = rightC;
    }

    if (dinhGoc != k) {
        swap(arr[k], arr[dinhGoc]);
        heapify(arr, size, dinhGoc);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int l = 0, r = n - 1;
    //mergeSort(arr, n);
    //quickSort(arr, l, r);
    heapSort(arr, n);
    for (int i = 0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
