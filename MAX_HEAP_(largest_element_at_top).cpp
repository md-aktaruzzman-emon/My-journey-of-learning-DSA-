#include <iostream>
using namespace std;

#define MAX 50

class MaxHeap {
private:
    int heap[MAX];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Insert function
    void insert(int value) {
        int i = size;
        heap[i] = value;
        size++;

        // heapify up
        while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Display heap
    void display() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(2);
    heap.insert(8);
    heap.insert(15);
    
    heap.display();
    
    return 0;
}