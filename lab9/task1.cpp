#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    // place new element at end
    int i = size;
    heap[i] = value;
    size++;

    // bubble up until parent is larger
    int parent = (i - 1) / 2;
    while (i != 0 && heap[parent] < heap[i]) {
        swap(&heap[i], &heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void printHeap() {
    printf("Max-Heap Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}


int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    printHeap();  // Expected: 40 30 15 10 20

    return 0;
}