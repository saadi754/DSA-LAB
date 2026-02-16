#include <stdio.h>

#define MAX 3

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

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    printf("Current Top Index: %d\n", top);
    return 0;
}