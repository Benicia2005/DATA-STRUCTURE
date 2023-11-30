#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int array[MAX_SIZE];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->array[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

bool areSameStacks(struct Stack* stack1, struct Stack* stack2) {
    if (stack1->top != stack2->top) {
        return false;
    }

    for (int i = 0; i <= stack1->top; i++) {
        if (stack1->array[i] != stack2->array[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    struct Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);
    push(&stack1, 4);

    push(&stack2, 1);
    push(&stack2, 2);
    push(&stack2, 3);
    push(&stack2, 4);

    if (areSameStacks(&stack1, &stack2)) {
        printf("Like Elements\n");
    } else {
        printf("Dislike Elements\n");
    }

    return 0;
}
