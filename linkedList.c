#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node with a given
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//Function to traverse and print the list
void traverseList(struct Node* head){
    struct Node* current = head;
    while(current != NULL){
        printf("%d -> " , current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to delete a node by its key value
void deleteNode(struct Node** head, int key){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Key not found\\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main(){
    struct Node* head = NULL;

    //Insert nodes at the beginning of the list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);

    printf("Initial list: \n");
    traverseList(head);
     
    
    //Delete a node and print the list again;
    printf("\nDeleting node with data 20:\n");
    deleteNode(&head, 20);
    traverseList(head);   

    //Try deleting a node that doesn't exist;
    printf("\nTrying to delete a node with data 50 (not in the list):\n");
    deleteNode(&head, 50);
    traverseList(head);

    //Delete the head node and print the list again
    printf("\nDeleting node with data 40 (head mode):\n");
    deleteNode(&head, 40);
    traverseList(head);     

      

    printf("\n----------------------------------END CODE----------------------------------------------");
    return 0;
}
