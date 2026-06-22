#include <iostream>
using namespace std;


struct Node {
    int data;
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

     
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
  
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }


    cout << "\nLinked List: ";

    temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    return 0;
}