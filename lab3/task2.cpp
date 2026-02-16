#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define MAX 10001

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void reverseSequence() {
    printf("Enter 5 integers:\n");
    for (int i = 0; i < 5; i++) {
        int val;
        printf("Value %d: ", i + 1);
        scanf("%d", &val);
        push(val);
    }
    
    printf("Reversed sequence: ");
    while (top != -1) {
        printf("%d ", stack[top]);
        top--;
    }
    printf("\n");
}

void benchmark() {
    top = -1;
    
    clock_t start = clock();
    for (int i = 0; i < 10000; i++) {
        push(i);
    }
    clock_t end = clock();
    double push_time = double(end - start) / CLOCKS_PER_SEC * 1000000;
    
    printf("Time to push 10000 elements: %.2f microseconds\n", push_time);
    
    start = clock();
    for (int i = 0; i < 10000; i++) {
        pop();
    }
    end = clock();
    double pop_time = double(end - start) / CLOCKS_PER_SEC * 1000000;
    
    printf("Time to pop 10000 elements: %.2f microseconds\n", pop_time);
    printf("Total time: %.2f microseconds\n", push_time + pop_time);
}

int main() {
    int choice;
    int value;
    
    while (1) {
        printf("\n=== Stack Operations Menu ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Reverse Sequence (5 integers)\n");
        printf("6. Benchmark (Push/Pop 10000 elements)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
                
            case 2:
                pop();
                break;
                
            case 3:
                if (peek() != -1) {
                    printf("Top element: %d\n", peek());
                }
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                reverseSequence();
                break;
                
            case 6:
                benchmark();
                break;
                
            case 7:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}