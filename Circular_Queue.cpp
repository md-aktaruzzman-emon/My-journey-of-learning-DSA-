#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int queue[MAX];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue (insert)
    void enqueue(int value) {
        // check overflow
        if ((rear + 1) % MAX == front) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        // first element
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;
        cout << value << " inserted into queue" << endl;
    }

    // Dequeue (delete)
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! Nothing to delete" << endl;
            return;
        }

        cout << queue[front] << " deleted from queue" << endl;

        // only one element
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Display queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are: ";

        int i = front;
        while (true) {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
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
