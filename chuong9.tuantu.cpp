#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm kiếm tuần tự
int SEQUEN_SEARCH(const vector<int>& k, int n, int X) {
    int i = 0;               // Bước 1: Khởi tạo i
    vector<int> arr = k;     // Sao chép mảng k vào mảng arr
    arr.push_back(X);        // Thêm X vào cuối mảng arr

    // Bước 2: Tìm kiếm phần tử X trong mảng
    while (arr[i] != X) {    
        i++;
    }

    // Bước 3: Kiểm tra kết quả
    if (i == n) {
        return 0;  // Nếu không tìm thấy X, trả về 0
    } else {
        return i + 1;  // Nếu tìm thấy X, trả về vị trí (i + 1)
    }
}

int main() {
    int n, X;
    
    // Nhập số lượng phần tử trong mảng
    cout << "Nhap so luong phan tu trong mang: ";
    cin >> n;
    
    vector<int> k(n);
    // Nhập các phần tử vào mảng
    cout << "Nhap cac phan tu trong mang: ";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    // Nhập giá trị X cần tìm
    cout << "Nhap gia tri X can tim: ";
    cin >> X;

    // Gọi hàm tìm kiếm tuần tự và in kết quả
    int result = SEQUEN_SEARCH(k, n, X);
    if (result == 0) {
        cout << "Khong tim thay gia tri X trong mang." << endl;
    } else {
        cout << "Gia tri X duoc tim thay tai vi tri: " << result << endl;
    }

    return 0;
}
