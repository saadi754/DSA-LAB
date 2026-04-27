#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;  // -1 means empty
}

void insert(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

int search(int key) {
    int index = key % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;  // found
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }

    return -1;  // not found
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d]: %d\n", i, hashTable[i]);
}

int main() {
    initTable();

    insert(42);  // 42 % 10 = 2
    insert(12);  // 12 % 10 = 2 → collision → goes to 3
    insert(25);  // 25 % 10 = 5

    display();

    int result = search(12);
    if (result != -1)
        printf("\nFound 12 at index %d\n", result);
    else
        printf("\n12 not found\n");

    return 0;
}