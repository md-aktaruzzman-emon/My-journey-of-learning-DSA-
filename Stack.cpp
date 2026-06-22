#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! Cannot insert " << value << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack" << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Nothing to pop" << endl;
        } else {
            cout << arr[top] << " popped from stack" << endl;
            top--;
        }
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}