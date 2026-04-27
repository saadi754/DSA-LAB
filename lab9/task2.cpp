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

    int i = size;
    heap[i] = value;
    size++;

    int parent = (i - 1) / 2;
    while (i != 0 && heap[parent] < heap[i]) {
        swap(&heap[i], &heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void heapify(int i) {
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);  // push down further if needed
    }
}

int extractMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int maxVal = heap[0];       // save the root (highest priority)
    heap[0] = heap[size - 1];  // move last element to root
    size--;
    heapify(0);                // push new root down to correct spot

    return maxVal;
}

void printHeap() {
    printf("Heap Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Bonus: Heap Sort — extracts all elements in descending order
void heapSort() {
    printf("\n--- Heap Sort ---\n");
    printf("Sorted (descending): ");
    while (size > 0)
        printf("%d ", extractMax());
    printf("\n");
}

int main() {
    // Insert patient priority levels
    insert(3);
    insert(9);
    insert(2);
    insert(1);
    insert(4);
    insert(5);

    printf("After all insertions:\n");
    printHeap();

    printf("\nTreating top 3 patients:\n");
    printf("Patient priority: %d\n", extractMax());
    printf("Patient priority: %d\n", extractMax());
    printf("Patient priority: %d\n", extractMax());

    printf("\nRemaining heap:\n");
    printHeap();

    heapSort();  // bonus

    return 0;
}