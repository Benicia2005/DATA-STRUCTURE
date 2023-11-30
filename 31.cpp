#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

// Function to push an element to the back of the queue
void push(int x) {
    if (top1 == MAX_SIZE - 1) {
        printf("Queue is full. Cannot push.\n");
        return;
    }

    stack1[++top1] = x;
    printf("Pushed: %d\n", x);
}

// Function to pop an element from the front of the queue
int pop() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty. Cannot pop.\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }

    int popped = stack2[top2--];
    printf("Popped: %d\n", popped);
    return popped;
}

// Function to peek at the element at the front of the queue
int peek() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }

    int front = stack2[top2];
    printf("Peek: %d\n", front);
    return front;
}

// Function to check if the queue is empty
int empty() {
    return (top1 == -1 && top2 == -1);
}

int main() {
    // Test the queue operations
    push(1);
    push(2);
    push(3);

    peek();
    pop();
    peek();

    push(4);
    push(5);

    while (!empty()) {
        pop();
    }

    pop(); // Trying to pop from an empty queue

    return 0;
}
