#include <stdio.h>
#include <stdlib.h>

// Define structure for stack
typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

// Function to create a new stack
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if a stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(Stack *stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function to add the top element of Stack1 with the bottom element of Stack2
int addTopBottom(Stack *stack1, Stack *stack2) {
    int topElement = pop(stack1);
    int bottomElement = pop(stack2);

    if (topElement == -1 || bottomElement == -1) {
        printf("Error: Stacks are not properly initialized.\n");
        return -1;
    }

    return topElement + bottomElement;
}

int main() {
    // Example usage
    Stack *stack1 = createStack(4);
    push(stack1, 1);
    push(stack1, 2);
    push(stack1, 3);
    push(stack1, 4);

    Stack *stack2 = createStack(4);
    push(stack2, 9);
    push(stack2, 6);
    push(stack2, 7);
    push(stack2, 4);

    int result1 = addTopBottom(stack1, stack2);
    printf("Output 1: %d\n", result1);

    // Free allocated memory
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);

    return 0;
}
