#include <iostream>
using namespace std;

// Hàm thực hiện thuật toán Selection Sort
void Selectionsorting(int a[], int n) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Giả sử phần tử nhỏ nhất là a[i]
        for (int j = i + 1; j < n; j++) {
            if (a[minIndex] > a[j]) {
                minIndex = j; // Cập nhật chỉ số phần tử nhỏ nhất
            }
        }
        // Hoán đổi giá trị của a[i] với a[minIndex]
        tmp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = tmp;
    }
}

// Hàm in mảng
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Hàm main
int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Gọi hàm Selectionsorting
    Selectionsorting(a, n);

    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
