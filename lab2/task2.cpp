#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int val) {
    struct Node* newNode = createNode(val);
    
    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(int val) {
    clock_t start = clock();
    
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == val) {
            clock_t end = clock();
            double time_used = double(end - start) / CLOCKS_PER_SEC * 1000000;
            cout << "Found: " << val << " | Time: " << time_used << " microseconds" << endl;
            return;
        }
        temp = temp->next;
    }
    
    clock_t end = clock();
    double time_used = double(end - start) / CLOCKS_PER_SEC * 1000000;
    cout << "Not Found | Time: " << time_used << " microseconds" << endl;
}

void display() {
    cout << "List: ";
    struct Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    int size, value;
    
    cout << "Enter desired size of linked list: ";
    cin >> size;
    
    cout << "Enter " << size << " values:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Value " << (i+1) << ": ";
        cin >> value;
        insertAtEnd(value);
    }
    
    cout << endl;
    display();
    cout << endl;
    
    int choice = 1;
    while(choice) {
        int searchVal;
        cout << "Enter value to search (0 to exit): ";
        cin >> searchVal;
        
        if(searchVal == 0) break;
        
        search(searchVal);
        cout << endl;
    }
    
    return 0;
}