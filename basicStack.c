#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the stack
struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap is full. Cannot add element.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to the stack.\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack is already empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from the stack.\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Display the entire stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// View an element at a specific position
void viewAtPosition(int position) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    int count = 1;

    while (temp != NULL) {
        if (count == position) {
            printf("Element at position %d: %d\n", position, temp->data);
            return;
        }
        temp = temp->next;
        count++;
    }
    printf("Invalid position: %d\n", position);
}

// Main function
int main() {
    int choice, value, position;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. View Element at Specific Position\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter the position to view: ");
                scanf("%d", &position);
                viewAtPosition(position);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
