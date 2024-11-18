#include <iostream>
using namespace std;

// �?nh nghia c?u tr�c c?a m?t n�t trong danh s�ch
struct Node {
    int data;       // Gi� tr? c?a n�t
    Node* next;     

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;    

public:
    // Constructor: Kh?i t?o danh s�ch r?ng
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Th�m m?t ph?n t? v�o cu?i danh s�ch
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // Danh s�ch r?ng
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }

    // Th�m m?t ph?n t? v�o d?u danh s�ch
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head; 
        head = newNode;     
    }

    // X�a m?t n�t theo gi� tr?
    void deleteNode(int value) {
        // Tru?ng h?p danh s�ch r?ng
        if (head == nullptr) {
            cout << "Danh sach rong, khong the xoa." << endl;
            return;
        }

        // Tru?ng h?p x�a n�t d?u ti�n
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;      
            return;
        }

        // Duy?t danh s�ch d? t�m n�t c?n x�a
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // N?u kh�ng t�m th?y n�t c?n x�a
        if (current->next == nullptr) {
            cout << "Khong tim thay gia tri " << value << " trong danh sach." << endl;
            return;
        }

        // Tru?ng h?p x�a n�t ? gi?a ho?c cu?i danh s�ch
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;                        
    }

    // Hi?n th? danh s�ch
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

    // Th�m ph?n t? v�o danh s�ch
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    // Hi?n th? danh s�ch
    list.display();

    // X�a m?t ph?n t?
    list.deleteNode(20);
    list.display();

    // X�a m?t ph?n t? kh�ng t?n t?i
    list.deleteNode(100);

    return 0;
}
