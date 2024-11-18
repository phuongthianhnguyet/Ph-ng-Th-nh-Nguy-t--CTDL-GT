#include <iostream>
using namespace std;

// Ham de dieu chinh heap tai vi tri k
void setupHeap(int a[], int k, int n) {
    int x = a[k];
    while (k < n / 2) {
        int j = 2 * k + 1;
        if (j + 1 < n && a[j] < a[j + 1]) j++;
        if (x >= a[j]) break;
        a[k] = a[j];
        k = j;
    }
    a[k] = x;
}

// Ham de xay dung heap tu mot mang
void makeHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        setupHeap(a, i, n);
    }
}

// Thuat toan sap xep Heap Sort
void heapSort(int a[], int n) {
    makeHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        setupHeap(a, 0, i);
    }
}

// Ham nhap mang tu ban phim
void inputArray(int a[], int &n) {
    cin >> n;
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    int a[n];
    inputArray(a, n);

    heapSort(a, n);

    cout << "Mang sau khi sap xep la: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}