#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

int main(){
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));

    first->data=100;
    first->next=second;

    second->data=200;
    second->next=NULL;

    struct Node* temp = first;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;   
    }
    cout<<endl;
}