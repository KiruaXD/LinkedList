#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INT,
    FLOAT,
    CHAR
} DataType;

typedef union {
    int intData;
    float floatData;
    char charData;
} Data;

typedef struct Node {
    DataType dataType;
    Data data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtFront(DataType dataType, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dataType = dataType;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void deleteAtFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    head = temp->next;
    free(temp);
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        switch (temp->dataType) {
            case INT:
                printf("%d ", temp->data.intData);
                break;
            case FLOAT:
                printf("%f ", temp->data.floatData);
                break;
            case CHAR:
                printf("%c ", temp->data.charData);
                break;
            // Add more cases for other data types
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtFront(INT, (Data){.intData = 3});
    insertAtFront(FLOAT, (Data){.floatData = 2.5});
    insertAtFront(CHAR, (Data){.charData = 'A'});

    printf("Initial list: ");
    printList();

    deleteAtFront();
    printf("List after deleting from front: ");
    printList();

    return 0;
}
