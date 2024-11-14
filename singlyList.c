#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the singly linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display all elements in the linked list.
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("The List is:\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to retrieve and display the third element in the list.
void displayThirdElement(struct Node* head) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL && position < 3) {
        current = current->next;
        position++;
    }

    if (current != NULL) {
        printf("The third element is: %d\n", current->data);
    } else {
        printf("The list does not have a third element.\n");
    }
}

// Function to calculate the sum of all elements in the list.
int sumOfList(struct Node* head) {
    struct Node* current = head;
    int sum = 0;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int data, i;

    // Get 4 elements from the user and add to the list
    printf("Please enter 4 integers:\n");
    for (i = 0; i < 4; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        
        // Create a new node and add it to the list
        if (head == NULL) {
            head = createNode(data);
            temp = head;
        } else {
            temp->next = createNode(data);
            temp = temp->next;
        }
    }

    // Display all elements in the list.
    displayList(head);

    // Display the third element in the list.
    displayThirdElement(head);

    // Calculate and display the sum of all elements in the list.
    int sum = sumOfList(head);
    printf("Sum: %d\n", sum);

    return 0;
}
