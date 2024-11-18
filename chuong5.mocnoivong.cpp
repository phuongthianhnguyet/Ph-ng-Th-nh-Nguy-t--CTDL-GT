#include <iostream>
using namespace std;

// Dinh nghia cau truc cua mot nut trong danh sach moc noi vong
struct Node {
    int data;       
    Node* next;    
};

// Ham tao mot nut moi
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Ham them vao phan tu vao danh sach tai vi tri bat ki
void addElement(Node** head, int newData, int pos) {
    Node* newNode = createNode(newData);

    if (*head == nullptr) { 
        *head = newNode;
        newNode->next = *head;
    } else if (pos == 0) { 
        Node* temp = *head;
        while (temp->next != *head) { 
            temp = temp->next;
        }
        temp->next = newNode;   
        newNode->next = *head;  
        *head = newNode;        
    } else { 
        Node* temp = *head;
        for (int i = 1; i < pos && temp->next != *head; i++) {
            temp = temp->next; 
        }
        newNode->next = temp->next;
        temp->next = newNode;       
    }
}

// Ham hien thi danh sach
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Ham giai phong bo nho danh sach
void freeList(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;
    Node* nextNode;

    do {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    } while (temp != *head);

    *head = nullptr;
}

// Chuong trinh chinh
int main() {
    Node* head = nullptr; 

    // Them phan tu vao danh sach
    addElement(&head, 10, 0); 
    addElement(&head, 20, 1); 
    addElement(&head, 15, 1);
    addElement(&head, 5, 0); 

    // Hien thi danh sach
    cout << "Danh sach hien tai: ";
    displayList(head);

    // Giai phong bo nho
    freeList(&head);

    return 0;
}
