#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Simple insertion (not BST, basic tree style)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (root->left == NULL) {
        root->left = createNode(value);
    }
    else if (root->right == NULL) {
        root->right = createNode(value);
    }
    else {
        insert(root->left, value);
    }

    return root;
}

// Inorder Traversal: Left → Root → Right
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, value;

    cout << "How many nodes? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}