#include <iostream>
using namespace std;

class Cstack {
private:
    int* StkArr;  
    int StkTop;   
    int StkMax;    

public:
    explicit Cstack(int size) {
        StkArr = new int[size];
        StkMax = size;
        StkTop = -1; 
    }

    // Destructor: Gi?i phóng b? nh?
    ~Cstack() {
        delete[] StkArr;
    }

    // Ki?m tra stack r?ng
    bool isEmpty() const {
        return StkTop == -1;
    }

    // Ki?m tra stack d?y
    bool isFull() const {
        return StkTop == StkMax - 1;
    }

    // L?y ph?n t? ra kh?i stack
    bool pop(int& outitem) {
        if (isEmpty()) {
            return false; 
        } else {
            outitem = StkArr[StkTop--];
            return true;
        }
    }

    // Thêm ph?n t? vào stack
    bool push(int newitem) {
        if (isFull()) {
            return false; // Stack d?y, không th? thêm
        } else {
            StkArr[++StkTop] = newitem;
            return true; // Thêm thành công
        }
    }

    // L?y ph?n t? trên cùng c?a stack mà không xóa
    bool peek(int& topitem) const {
        if (isEmpty()) {
            return false; // Stack r?ng, không có ph?n t?
        } else {
            topitem = StkArr[StkTop];
            return true; // L?y thành công
        }
    }

    // Hi?n th? các ph?n t? trong stack
    void display() const {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
        } else {
            cout << "Cac phan tu trong stack: ";
            for (int i = 0; i <= StkTop; i++) {
                cout << StkArr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Hàm chính d? ki?m tra ch?c nang c?a l?p Cstack
int main() {
    // T?o stack v?i kích thu?c t?i da là 5
    Cstack myStack(5);

    // Thêm ph?n t? vào stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Hi?n th? stack
    myStack.display();

    // L?y ph?n t? ra kh?i stack
    int poppedValue;
    if (myStack.pop(poppedValue)) {
        cout << "Phan tu da lay ra: " << poppedValue << endl;
    } else {
        cout << "Khong the lay phan tu (stack rong)" << endl;
    }

    // Hi?n th? stack sau khi pop
    myStack.display();

    // L?y ph?n t? trên cùng mà không xóa
    int topValue;
    if (myStack.peek(topValue)) {
        cout << "Phan tu tren cung cua stack: " << topValue << endl;
    } else {
        cout << "Khong co phan tu tren cung (stack rong)" << endl;
    }

    // Ki?m tra stack r?ng ho?c d?y
    if (myStack.isEmpty()) {
        cout << "Stack dang rong" << endl;
    } else if (myStack.isFull()) {
        cout << "Stack da day" << endl;
    } else {
        cout << "Stack khong rong cung khong day" << endl;
    }

    return 0;
}
