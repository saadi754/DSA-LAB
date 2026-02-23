#include <stdio.h>
#include <iostream>
#include <time.h>
#define MAX 4

using namespace std;
int queue[MAX];
int front = -1;
int rear = -1;
int element_count = 0;

void enqueue(int value){
    if(element_count == MAX){
        cout<<" Queue Overflow ! Cannot enqueue = "<<value<<endl;
    }else{
        if(front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        element_count++;
        cout<<"Enqueued to queue = "<<value<<endl;
    }
}

int dequeue(){
    if(element_count == 0){
        cout<<" Queue Underflow ! Cannot dequeue"<<endl;
        return -1;
    }else{
        int value = queue[front];
        front = (front + 1) % MAX;
        element_count--;
        cout<<"Dequeued from queue = "<<value<<endl;
        return value;
    }
}

void display(){
    if(element_count == 0){
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    cout<<"Queue elements (front to rear): ";
    int count = 0;
    int i = front;
    while(count < element_count){
        cout<<queue[i]<<" ";
        i = (i + 1) % MAX;
        count++;
    }
    cout<<endl;
}

void benchmark(){
    cout<<"\n--- Benchmarking Circular Queue with 50,000 operations ---"<<endl;
    clock_t start, end;
    double cpu_time_used;
    
    front = -1;
    rear = -1;
    element_count = 0;
    
    start = clock();
    
    for(int i = 0; i < 50000; i++){
        if(element_count < MAX){
            if(front == -1) front = 0;
            rear = (rear + 1) % MAX;
            queue[rear] = i;
            element_count++;
        }else{
            front = (front + 1) % MAX;
            element_count--;
            rear = (rear + 1) % MAX;
            queue[rear] = i;
            element_count++;
        }
    }
    
    while(element_count > 0){
        front = (front + 1) % MAX;
        element_count--;
    }
    
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    cout<<"Time taken for 50,000 operations: "<<cpu_time_used<<" seconds"<<endl;
    cout<<"Modulo arithmetic handled efficiently!"<<endl;
}

void enfifty(){
    cout<<"\n--- Enqueuing 50,000 entries starting from 5 ---"<<endl;
    clock_t start, end;
    double cpu_time_used;
    
    front = -1;
    rear = -1;
    element_count = 0;
    
    start = clock();
    
    for(int i = 5; i < 50005; i++){
        if(element_count < MAX){
            if(front == -1) front = 0;
            rear = (rear + 1) % MAX;
            queue[rear] = i;
            element_count++;
        }else{
            front = (front + 1) % MAX;
            element_count--;
            rear = (rear + 1) % MAX;
            queue[rear] = i;
            element_count++;
        }
    }
    
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout<<"Successfully enqueued 50,000 entries!"<<endl;
    cout<<"Time taken: "<<cpu_time_used<<" seconds"<<endl;
    cout<<"Queue currently has "<<element_count<<" elements"<<endl;
};

int main(){
    int choice, value;
    
    while(1){
        cout<<"\n--- Circular Queue Menu ---"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Benchmark (50,000 operations)"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"6. enqueu 50,000 "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
        
        switch(choice){
            case 1:
                cout<<"Enter value to enqueue: ";
                cin>>value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                benchmark();
                break;
            case 5:
                cout<<"Exiting program..."<<endl;
                return 0;
            case 6:
                enfifty();
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    return 0;
}
