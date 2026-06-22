#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into Min Heap
void insert(int value) {
    int i = size;
    heap[i] = value;
    size++;

    // heapify up
    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Display heap
void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n, value;

    printf("How many elements? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        insert(value);
    }

    printf("\nMin Heap: ");
    display();

    return 0;
}