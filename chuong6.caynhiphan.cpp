#include <iostream>
using namespace std;

// dinh nghia cau truc cua mot nut trong cay nhi phan
struct Node {
    int data;
    Node* left;
    Node* right;
};

//Ham tao mot nut moi voi gia tri dau vao
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ham duyet truoc (preorder traversal) cua cay nhi phan
void preorder(Node* root) {
    if (root != NULL) {
        // In ra gia tri cua cac nut goc
        cout << root->data << " ";
        // duyet cay con ben trai
        preorder(root->left);
        // Duyet cay con ben phai
        preorder(root->right);
    }
}

//Ham duyet giua (inorder) cua cay nhi phan
void inorder(Node* root){
	if(root != NULL){
		//Duyet cay con ben trai
		inorder(root->left);
		//In ra gia tri cua nut goc
		cout<<root->data<<" ";
		//Duyet cay con ben phai
		inorder(root->right);
	}
}

//Ham duyet sau cua cay nhi phan
void postorder(Node* root){
	if(root != NULL){
		//Duyet cau con ben trai
		postorder (root->left);
		//Duyet cay con ben phai
		postorder (root->right);
		//In goc
		cout<<root->data<<" ";
	}
}

// Ham them nut moi vao cay nhi phan  (su dung de quy)
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    char direction;
    cout << "Ban muon chen " << value << " vao trai (l) hay phai (r) cua " << root->data << "? ";
    cin >> direction;

    if (direction == 'l' || direction == 'L') {
        root->left = insertNode(root->left, value);
    } else if (direction == 'r' || direction == 'R') {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "Nhap so phan tu cua cay (so node): ";
    cin >> n;

    // Nhap cac phan tu vao cay nhi phan 
    for (int i = 0; i < n; i++) {
        cout << "Nhap gia tri cho phan tu " << i + 1 << ": ";
        cin >> value;
        if (root == NULL) {
            root = createNode(value); // Phan tu dau tien se laf goc cua cay
        } else {
            root = insertNode(root, value);
        }
    }

    // In ra thu tu duyet truoc cua cay nhi phan
    cout << "\n- Duyet truoc (Preorder) cua cay: ";
    preorder(root);
    //In ra thu tu duyet giua cua cay nhi phan 
    cout<<"\n- Duyet giua (inorder) cua cay nhi phan: ";
    inorder(root);
    //In ra thu tu duyet dau cua cay nhi phan
    cout<<"\n- Duyet sau (postorder) cua cay nhi phan: ";
	postorder(root);  

    return 0;
}