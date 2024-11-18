#include <iostream>
using namespace std;

class Queue {
private:
    int* QArray;   
    int QMax;      
    int QNumItems; 
    int QFront;    
    int QRear;      

public:
    // Constructor: Kh?i t?o Queue
    explicit Queue(int size) {
        QArray = new int[size];
        QMax = size;
        QNumItems = 0;
        QFront = -1;
        QRear = -1;
    }

    // Destructor: Gi?i phóng b? nh?
    ~Queue() {
        delete[] QArray;
    }

    // Ki?m tra Queue r?ng
    bool isEmpty() const {
        return QNumItems == 0;
    }

    // Ki?m tra Queue d?y
    bool isFull() const {
        return QNumItems == QMax;
    }

    // Thêm ph?n t? vào Queue
    bool append(int newItem) {
        if (isFull()) {
            return false; 
        }

        if (QNumItems == 0) {
            QFront = 0;
        }

        QRear = (QRear + 1) % QMax;
        QArray[QRear] = newItem;    
        QNumItems++;                
        return true;
    }

    // L?y ph?n t? ra kh?i Queue
    bool remove(int& outItem) {
        if (isEmpty()) {
            return false; 
        }

        outItem = QArray[QFront];  
        QFront = (QFront + 1) % QMax; 
        QNumItems--;               
        if (QNumItems == 0) {
            QFront = QRear = -1;  
        }
        return true;
    }

    // Hi?n th? các ph?n t? trong Queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
        } else {
            cout << "Cac phan tu trong Queue: ";
            int index = QFront;
            for (int i = 0; i < QNumItems; i++) {
                cout << QArray[index] << " ";
                index = (index + 1) % QMax; 
            }
            cout << endl;
        }
    }
};

// Hàm chính d? ki?m tra ch?c nang c?a Queue
int main() {
   
    Queue myQueue(5);

    // Thêm ph?n t? vào Queue
    myQueue.append(10);
    myQueue.append(20);
    myQueue.append(30);
    myQueue.append(40);

    // Hi?n th? Queue
    myQueue.display();

    // L?y ph?n t? ra kh?i Queue
    int removedItem;
    if (myQueue.remove(removedItem)) {
        cout << "Phan tu da lay ra: " << removedItem << endl;
    }

    // Hi?n th? Queue sau khi l?y ph?n t?
    myQueue.display();

    // Thêm ph?n t? khác vào Queue
    myQueue.append(50);
    myQueue.append(60); 

    // Hi?n th? l?i Queue
    myQueue.display();

    return 0;
}
