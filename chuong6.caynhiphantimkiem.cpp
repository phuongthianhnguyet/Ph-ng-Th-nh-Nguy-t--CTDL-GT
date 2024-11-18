#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Hàm thêm ph?n t? vào cây nh? phân tìm ki?m
int insert(int x, Node*& root) {
    if (root == NULL) {
        root = new Node(x);
        return (root == NULL) ? -1 : 1; // Ki?m tra c?p phát b? nh?
    }
    if (x == root->data) return 0; // Giá tr? dã t?n t?i
    return (x < root->data) ? insert(x, root->left) : insert(x, root->right);
}

// Hàm xóa ph?n t? kh?i cây nh? phân tìm ki?m
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Nút c?n xóa du?c tìm th?y
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Tru?ng h?p có 2 con
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Hàm tìm nút có khóa nh? nh?t
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Hàm tìm nút có khóa l?n nh?t
Node* findMax(Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Hàm in cây nh? phân theo th? t? tru?c (NLR)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Hàm in cây nh? phân theo th? t? gi?a (LNR)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Hàm in cây nh? phân theo th? t? sau (LRN)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Hàm in cây d?ng c?u trúc ngang
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
    cout << "1. Thêm ph?n t? vào cây\n";
    cout << "2. Xóa ph?n t? kh?i cây\n";
    cout << "3. Duy?t cây theo th? t? tru?c, gi?a, sau\n";
    cout << "4. Tìm nút nh? nh?t và l?n nh?t\n";
    cout << "5. In cây d?ng c?u trúc\n";
    cout << "6. Thoát\n";
    cout << "=====================================\n";
}

int main() {
    Node* root = NULL; // Kh?i t?o cây r?ng
    int choice, value;

    while (true) {
        menu();
        cout << "Ch?n thao tác: ";
        cin >> choice;

        switch (choice) {
        case 1: // Thêm ph?n t?
            cout << "Nh?p giá tr? c?n thêm: ";
            cin >> value;
            if (insert(value, root) == 1) {
                cout << "Thêm thành công!\n";
            } else {
                cout << "Giá tr? dã t?n t?i ho?c thêm th?t b?i.\n";
            }
            break;

        case 2: // Xóa ph?n t?
            cout << "Nh?p giá tr? c?n xóa: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Ðã xóa giá tr? " << value << " n?u t?n t?i.\n";
            break;

        case 3: // Duy?t cây
            cout << "Duy?t cây theo th? t? tru?c (NLR): ";
            preorder(root);
            cout << "\nDuy?t cây theo th? t? gi?a (LNR): ";
            inorder(root);
            cout << "\nDuy?t cây theo th? t? sau (LRN): ";
            postorder(root);
            cout << endl;
            break;

        case 4: // Tìm nút nh? nh?t và l?n nh?t
            if (Node* minNode = findMin(root)) {
                cout << "Nút nh? nh?t: " << minNode->data << endl;
            } else {
                cout << "Cây r?ng.\n";
            }
            if (Node* maxNode = findMax(root)) {
                cout << "Nút l?n nh?t: " << maxNode->data << endl;
            } else {
                cout << "Cây r?ng.\n";
            }
            break;

        case 5: // In cây d?ng c?u trúc
            cout << "Cây hi?n t?i:\n";
            printTree(root);
            break;

        case 6: // Thoát chuong trình
            cout << "Thoát chuong trình.\n";
            return 0;

        default:
            cout << "L?a ch?n không h?p l?. Vui lòng th? l?i.\n";
        }
    }

    return 0;
}
