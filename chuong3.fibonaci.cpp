#include <iostream>
using namespace std;

// Hàm tính Fibonacci bằng đệ quy
int fibonacci(int n) {
    // Điều kiện cơ sở
    if (n == 0) {
        return 0;  // F(0) = 0
    } else if (n == 1) {
        return 1;  // F(1) = 1
    } else {
        // Đệ quy tính F(n) = F(n-1) + F(n-2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    // Nhập vào số n để tính Fibonacci(n)
    cout << "Nhap so n: ";
    cin >> n;

    // Tính và in ra Fibonacci(n)
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}
