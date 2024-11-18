#include <iostream>
using namespace std;

int main() {
    // Khai bao va khoi tao mang
    int arr[5] = {1, 2, 3, 4, 5};

    // Hien thi
    cout << "Cac phan tu cua mang la: ";

    //truy cap va in
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;

    // Tinh tong cac phan tu cua mang
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    cout << "Tong cac phan tu trong mang: " << sum << endl;

    // Tim gia tri lon nhat
    int maxVal = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    cout << "Gia tri lon nhat trong mang: " << maxVal << endl;

    // Tim gia tri nho nhat
    int minVal = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    cout << "Gia tri nho nhat trong mang: " << minVal << endl;

    return 0;
}
