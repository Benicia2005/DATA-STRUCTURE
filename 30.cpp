#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue node
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if a queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue a data into the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a data from the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Assuming -1 as an error value
    }

    int data = queue->front->data;
    struct QueueNode* temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

// Define the MyStack structure
struct MyStack {
    struct Queue* q1;
    struct Queue* q2;
};

// Function to initialize the MyStack
struct MyStack* initializeMyStack() {
    struct MyStack* myStack = (struct MyStack*)malloc(sizeof(struct MyStack));
    myStack->q1 = createQueue();
    myStack->q2 = createQueue();
    return myStack;
}

// Function to push an element onto the stack
void push(struct MyStack* myStack, int x) {
    enqueue(myStack->q1, x);

    // Move all elements from q2 to q1
    while (!isQueueEmpty(myStack->q2)) {
        enqueue(myStack->q1, dequeue(myStack->q2));
    }

    // Swap q1 and q2
    struct Queue* temp = myStack->q1;
    myStack->q1 = myStack->q2;
    myStack->q2 = temp;
}

// Function to pop an element from the stack
int pop(struct MyStack* myStack) {
    if (isQueueEmpty(myStack->q2)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an error value
    }

    return dequeue(myStack->q2);
}

// Function to return the top element of the stack
int top(struct MyStack* myStack) {
    if (isQueueEmpty(myStack->q2)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an error value
    }

    return myStack->q2->front->data;
}

// Function to check if the stack is empty
int empty(struct MyStack* myStack) {
    return isQueueEmpty(myStack->q2);
}

int main() {
    // Example usage
    struct MyStack* myStack = initializeMyStack();

    // Push elements onto the stack
    push(myStack, 1);
    push(myStack, 2);

    // Perform stack operations
    printf("Top of the stack: %d\n", top(myStack));
    printf("Pop: %d\n", pop(myStack));
    printf("Is the stack empty? %s\n", empty(myStack) ? "Yes" : "No");

    // Free allocated memory
    free(myStack->q1);
    free(myStack->q2);
    free(myStack);

    return 0;
}
