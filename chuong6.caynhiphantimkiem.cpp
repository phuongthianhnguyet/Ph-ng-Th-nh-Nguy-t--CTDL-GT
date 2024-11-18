#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// H�m th�m ph?n t? v�o c�y nh? ph�n t�m ki?m
int insert(int x, Node*& root) {
    if (root == NULL) {
        root = new Node(x);
        return (root == NULL) ? -1 : 1; // Ki?m tra c?p ph�t b? nh?
    }
    if (x == root->data) return 0; // Gi� tr? d� t?n t?i
    return (x < root->data) ? insert(x, root->left) : insert(x, root->right);
}

// H�m x�a ph?n t? kh?i c�y nh? ph�n t�m ki?m
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // N�t c?n x�a du?c t�m th?y
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Tru?ng h?p c� 2 con
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// H�m t�m n�t c� kh�a nh? nh?t
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// H�m t�m n�t c� kh�a l?n nh?t
Node* findMax(Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// H�m in c�y nh? ph�n theo th? t? tru?c (NLR)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// H�m in c�y nh? ph�n theo th? t? gi?a (LNR)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// H�m in c�y nh? ph�n theo th? t? sau (LRN)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// H�m in c�y d?ng c?u tr�c ngang
void printTree(Node* root, int space = 0, int height = 10) {
    if (root == NULL) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space);
}

// Menu ch?c nang
void menu() {
    cout << "================ MENU ================\n";
    cout << "1. Th�m ph?n t? v�o c�y\n";
    cout << "2. X�a ph?n t? kh?i c�y\n";
    cout << "3. Duy?t c�y theo th? t? tru?c, gi?a, sau\n";
    cout << "4. T�m n�t nh? nh?t v� l?n nh?t\n";
    cout << "5. In c�y d?ng c?u tr�c\n";
    cout << "6. Tho�t\n";
    cout << "=====================================\n";
}

int main() {
    Node* root = NULL; // Kh?i t?o c�y r?ng
    int choice, value;

    while (true) {
        menu();
        cout << "Ch?n thao t�c: ";
        cin >> choice;

        switch (choice) {
        case 1: // Th�m ph?n t?
            cout << "Nh?p gi� tr? c?n th�m: ";
            cin >> value;
            if (insert(value, root) == 1) {
                cout << "Th�m th�nh c�ng!\n";
            } else {
                cout << "Gi� tr? d� t?n t?i ho?c th�m th?t b?i.\n";
            }
            break;

        case 2: // X�a ph?n t?
            cout << "Nh?p gi� tr? c?n x�a: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "�� x�a gi� tr? " << value << " n?u t?n t?i.\n";
            break;

        case 3: // Duy?t c�y
            cout << "Duy?t c�y theo th? t? tru?c (NLR): ";
            preorder(root);
            cout << "\nDuy?t c�y theo th? t? gi?a (LNR): ";
            inorder(root);
            cout << "\nDuy?t c�y theo th? t? sau (LRN): ";
            postorder(root);
            cout << endl;
            break;

        case 4: // T�m n�t nh? nh?t v� l?n nh?t
            if (Node* minNode = findMin(root)) {
                cout << "N�t nh? nh?t: " << minNode->data << endl;
            } else {
                cout << "C�y r?ng.\n";
            }
            if (Node* maxNode = findMax(root)) {
                cout << "N�t l?n nh?t: " << maxNode->data << endl;
            } else {
                cout << "C�y r?ng.\n";
            }
            break;

        case 5: // In c�y d?ng c?u tr�c
            cout << "C�y hi?n t?i:\n";
            printTree(root);
            break;

        case 6: // Tho�t chuong tr�nh
            cout << "Tho�t chuong tr�nh.\n";
            return 0;

        default:
            cout << "L?a ch?n kh�ng h?p l?. Vui l�ng th? l?i.\n";
        }
    }

    return 0;
}
