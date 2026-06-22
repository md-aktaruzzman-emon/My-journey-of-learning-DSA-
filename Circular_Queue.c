#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue (insert)
void enqueue(int value) {
    // check overflow
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
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
    printf("%d inserted into queue\n", value);
}

// Dequeue (delete)
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);

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
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
