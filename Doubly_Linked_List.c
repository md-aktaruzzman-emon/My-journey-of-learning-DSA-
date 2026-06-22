#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, value;

    printf("How many nodes do you want? ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

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

    // Display forward
    printf("\nForward Traversal: ");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        if (temp->next == NULL) break; // stop at last node
        temp = temp->next;
    }
    printf("NULL\n");

    // Move to last node for backward traversal
    struct Node* last = temp;

    // Display backward
    printf("Backward Traversal: ");
    while (last != NULL) {
        printf("%d <-> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");

    return 0;
}