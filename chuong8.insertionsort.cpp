#include <iostream>
using namespace std;

// Hàm thực hiện thuật toán Insertion Sort
void insertsort(int a[], int n) {
    int x, i, j;
    // Duyệt từ phần tử thứ hai đến phần tử cuối cùng
    for (i = 1; i < n; i++) {
        x = a[i]; // Lấy giá trị của phần tử cần chèn
        j = i - 1; // Tìm vị trí thích hợp để chèn giá trị x
        
        // Di chuyển các phần tử lớn hơn x sang phải
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j]; // Di chuyển a[j] sang vị trí tiếp theo
            j = j - 1; // Tiếp tục tìm vị trí thích hợp
        }
        
        // Chèn giá trị x vào vị trí thích hợp
        a[j + 1] = x;
    }
}

// Hàm in mảng
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; // In phần tử của mảng
    }
    cout << endl; // Xuống dòng sau khi in mảng
}

// Hàm main
int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    int a[n]; // Khai báo mảng có n phần tử
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Nhập các phần tử của mảng
    }

    // Gọi hàm insertsort để sắp xếp mảng
    insertsort(a, n);

    // In kết quả sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, n);

    return 0;
}
