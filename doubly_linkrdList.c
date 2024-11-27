#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node with key %d deleted.\n", key);
}

// Function to delete a node at a given position
void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 0) {
        printf("Invalid position!\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position %d out of range.\n", position);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node at position %d deleted.\n", position);
}

// Function to traverse and print the linked list from head to tail
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List (forward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to traverse and print the linked list from tail to head
void traverseBackward(struct Node* tail) {
    struct Node* temp = tail;
    printf("Doubly Linked List (backward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function to test the doubly linked list operations
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    traverseForward(head);
    traverseBackward(tail);

    insertAtBeginning(&head, 0);
    traverseForward(head);
    traverseBackward(tail);

    insertAfterNode(head->next, 1);
    traverseForward(head);
    traverseBackward(tail);

    deleteNode(&head, 2);
    traverseForward(head);
    traverseBackward(tail);

    deleteNodeAtPosition(&head, 1);
    traverseForward(head);
    traverseBackward(tail);

    return 0;
}
