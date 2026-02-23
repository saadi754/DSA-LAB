#include <stdio.h>
#include <iostream>
#define MAX 4

using namespace std;
int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value){

    if(rear == MAX - 1){
        cout<<" Queue Overflow ! Cannot enqueue = "<<value<<endl;
    }else{
        rear++;
        queue[rear] = value;
        cout<<"entered to queue = "<<value<<endl;
    }
};

int main(){
    for(int i=0;i<=4;i++){
        int n;
        cout<<"enter-value = ";
        cin>>n;
        cout<<endl;
        enqueue(n);
    }
    cout<<"front index = "<<front<<"  ||  Rear index = "<<rear<<endl;
}