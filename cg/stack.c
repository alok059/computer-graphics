#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int top = -1;
int stack[MAX];

void push(int stack[], int *top, int value) {
    if (*top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = value;
    printf("%d pushed onto stack\n", value);
}

int pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

void display(int stack[], int top) {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            case 2:
                value = pop(stack, &top);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}