#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

int main() {
    int n, value;

    cout << "How many nodes do you want? ";
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node();

        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        // First node
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        // Other nodes
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Forward traversal
    cout << "\nForward Traversal: ";
    temp = head;
    Node* last = NULL;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        last = temp;        // save last node
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Backward traversal
    cout << "Backward Traversal: ";
    while (last != NULL) {
        cout << last->data << " <-> ";
        last = last->prev;
    }
    cout << "NULL" << endl;

    return 0;
}