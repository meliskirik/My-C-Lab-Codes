#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create and add a new node at the end of the list.
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display all elements in a list.
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

// Function to compare two lists for equality.
int compareLists(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0;  // Lists are not equal
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

// Function to merge two lists.
void mergeLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Add elements to list1
    insert(&list1, 10);
    insert(&list1, 20);
    insert(&list1, 30);

    // Add elements to list2
    insert(&list2, 10);
    insert(&list2, 20);
    insert(&list2, 30);

    // Display list 1
    printf("List 1\n");
    displayList(list1);

    // Display list 2
    printf("\nList 2\n");
    displayList(list2);

    // Compare the two lists
    if (compareLists(list1, list2)) {
        printf("\nThe 2 lists are equal.\n");
    } else {
        printf("\nThe 2 lists are not equal.\n");
    }

    // Merge the lists and display the merged list
    mergeLists(&list1, list2);
    printf("\n**************************\nThe merged list.\n");
    displayList(list1);

    return 0;
}
