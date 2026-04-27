#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}

void insert(int key) {
    int index = key % SIZE;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];  // insert at beginning
    hashTable[index] = newNode;

    printf("Inserted %d at index %d\n", key, index);
}

int search(int key) {
    int index = key % SIZE;
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key)
            return 1;  // found
        temp = temp->next;
    }

    return 0;  // not found
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[Index %d] -> ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initTable();

    insert(15);  // 15 % 7 = 1
    insert(11);  // 11 % 7 = 4
    insert(27);  // 27 % 7 = 6
    insert(8);   // 8  % 7 = 1  → collision at 1
    insert(12);  // 12 % 7 = 5
    insert(22);  // 22 % 7 = 1  → collision at 1

    display();

    printf("\nSearch 8:  %s\n", search(8)  ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");

    return 0;
}