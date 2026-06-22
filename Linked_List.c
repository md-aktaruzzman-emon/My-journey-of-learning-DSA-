#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, value;

    printf("How many nodes do you want? ");
    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    for (int i = 0; i < n; i++) {
        
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

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

    
    printf("\nLinked List: ");

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}