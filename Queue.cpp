#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue (insert)
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;
        cout << value << " inserted into queue" << endl;
    }

    // Dequeue (delete)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Nothing to delete" << endl;
            return;
        }

        cout << arr[front] << " deleted from queue" << endl;
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    // Display queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
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