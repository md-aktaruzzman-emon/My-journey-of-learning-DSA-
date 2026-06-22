#include <iostream>
using namespace std;

#define MAX 50

class MinHeap {
private:
    int heap[MAX];
    int size;

public:
    MinHeap() {
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
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Display heap
    void display() {
        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;
    int n, value;

    cout << "How many elements? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        h.insert(value);
    }

    h.display();

    return 0;
}