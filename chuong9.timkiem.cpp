#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm kiếm nhị phân
int binarySearch(vector<int>& k, int n, int X) {
    int l = 0;  // Chỉ số bắt đầu (l) của mảng
    int r = n - 1;  // Chỉ số cuối (r) của mảng
    int m;

    while (l <= r) {
        m = (l + r) / 2;  // Tính chỉ số giữa m

        if (X < k[m]) {
            r = m - 1;  // Nếu X nhỏ hơn phần tử ở giữa, tìm trong nửa bên trái
        } else if (X > k[m]) {
            l = m + 1;  // Nếu X lớn hơn phần tử ở giữa, tìm trong nửa bên phải
        } else {
            return m;  // Nếu tìm thấy, trả về chỉ số của phần tử
        }
    }

    return -1;  // Nếu không tìm thấy, trả về -1
}

int main() {
    int n, X;

    // Nhập số lượng phần tử trong mảng
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;

    vector<int> k(n);
    
    // Nhập các phần tử vào mảng
    cout << "Nhap cac phan tu trong mang (mang da duoc sap xep tang dan): ";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    // Nhập giá trị X cần tìm
    cout << "Nhap gia tri X can tim: ";
    cin >> X;

    // Gọi hàm tìm kiếm nhị phân và in kết quả
    int result = binarySearch(k, n, X);
    if (result == -1) {
        cout << "Khong tim thay gia tri X trong mang." << endl;
    } else {
        cout << "Gia tri X duoc tim thay tai vi tri: " << result << endl;
    }

    return 0;
}
