#include <iostream>
#include <string>
using namespace std;

// Dinh nghia cua mot nut trong danh sach
struct Node {
    int id;       
    string name;   
    Node* next;     
    Node* prev;    
};

// Tao nut moi
Node* createNode(int id, string name) {
    Node* newNode = new Node();
    newNode->id = id;
    newNode->name = name;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Them san pham vao dau danh sach
void insertAtHead(Node*& head, Node*& tail, int id, string name) {
    Node* newNode = createNode(id, name);
    if (head == nullptr) { // Danh sach trong
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Them san pham vao cuoi danh sach
void insertAtTail(Node*& head, Node*& tail, int id, string name) {
    Node* newNode = createNode(id, name);
    if (tail == nullptr) { // Danh sach trong
        head = tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

// Them san pham vao vi tri bat ki
void insertAtPosition(Node*& head, Node*& tail, int position, int id, string name) {
    if (position <= 0) {
        insertAtHead(head, tail, id, name);
        return;
    }

    Node* temp = head;
    int index = 0;

    while (temp != nullptr && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr || temp->next == nullptr) { // Nếu đến cuối danh sách
        insertAtTail(head, tail, id, name);
        return;
    }

    Node* newNode = createNode(id, name);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Xoa san pham theo ID
void deleteById(Node*& head, Node*& tail, int id) {
    if (head == nullptr) return; // Danh sach trong

    Node* temp = head;

    // Tim nut co ID
    while (temp != nullptr && temp->id != id) {
        temp = temp->next;
    }

    if (temp == nullptr) { // Khong tim thay
        cout << "Khong tim thay san pham ID: " << id << endl;
        return;
    }

    if (temp->prev != nullptr) { // Neu khong phai nut dau
        temp->prev->next = temp->next;
    } else { // Neu la nut dau
        head = temp->next;
    }

    if (temp->next != nullptr) { // Neu khong phai nut cuoi
        temp->next->prev = temp->prev;
    } else { // Neu la nut cuoi
        tail = temp->prev;
    }

    delete temp;
}

// Hien thi danh sach tu dau den cuoi
void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Ten: " << temp->name << endl;
        temp = temp->next;
    }
}

// Hien thi danh sach tu cuoi-dau
void displayBackward(Node* tail) {
    if (tail == nullptr) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    Node* temp = tail;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Ten: " << temp->name << endl;
        temp = temp->prev;
    }
}

// Giai phong bo nho
void freeList(Node*& head, Node*& tail) {
    Node* temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Chèn sản phẩm
    insertAtHead(head, tail, 1, "San pham A");
    insertAtTail(head, tail, 2, "San pham B");
    insertAtPosition(head, tail, 2, 3, "San pham C");

    cout << "Danh sach san pham (tu dau den cuoi):" << endl;
    displayForward(head);

    cout << "Danh sach san pham (tu cuoi ve dau):" << endl;
    displayBackward(tail);

    // Xoa san pham
    deleteById(head, tail, 2);
    cout << "Danh sach sau khi xoa san pham ID=2:" << endl;
    displayForward(head);

    // Giai phong bo nho
    freeList(head, tail);

    return 0;
}
