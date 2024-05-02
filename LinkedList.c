#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node* head = NULL;

void insertAtFront(int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int data, int position) {
    node *newNode = (node *)malloc(sizeof(node));
    if (position == 0) {
        insertAtFront(data);
        return;
    }

    node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    head = temp->next;
    free(temp);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    if (position == 0) {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    node *nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

void insertAtEnd(int data) {
    node *temp = head;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void printList() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtFront(3);
    insertAtFront(2);
    insertAtFront(1);

    printf("Initial list: ");
    printList();

    insertAtPosition(4, 2);
    printf("List after adding 4 at position 2: ");
    printList();

    deleteAtFront();
    printf("List after deleting from front: ");
    printList();

    deleteAtPosition(1);
    printf("List after deleting from position 1: ");
    printList();

    insertAtEnd(5);
    printf("List after inserting 5 at the end: ");
    printList();

    deleteAtEnd();
    printf("List after deleting from end: ");
    printList();

    return 0;
}
