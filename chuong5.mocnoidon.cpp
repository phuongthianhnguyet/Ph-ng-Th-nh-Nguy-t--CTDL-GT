#include <iostream>
using namespace std;

// Ð?nh nghia c?u trúc c?a m?t nút trong danh sách
struct Node {
    int data;       // Giá tr? c?a nút
    Node* next;     

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;    

public:
    // Constructor: Kh?i t?o danh sách r?ng
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Thêm m?t ph?n t? vào cu?i danh sách
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // Danh sách r?ng
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }

    // Thêm m?t ph?n t? vào d?u danh sách
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head; 
        head = newNode;     
    }

    // Xóa m?t nút theo giá tr?
    void deleteNode(int value) {
        // Tru?ng h?p danh sách r?ng
        if (head == nullptr) {
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Tru?ng h?p xóa nút d?u tiên
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;      
            return;
        }

        // Duy?t danh sách d? tìm nút c?n xóa
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // N?u không tìm th?y nút c?n xóa
        if (current->next == nullptr) {
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Tru?ng h?p xóa nút ? gi?a ho?c cu?i danh sách
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;                        
    }

    // Hi?n th? danh sách
    void display() const {
        if (head == nullptr) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        cout << "Danh sach lien ket: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Thêm ph?n t? vào danh sách
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    // Hi?n th? danh sách
    list.display();

    // Xóa m?t ph?n t?
    list.deleteNode(20);
    list.display();

    // Xóa m?t ph?n t? không t?n t?i
    list.deleteNode(100);

    return 0;
}
