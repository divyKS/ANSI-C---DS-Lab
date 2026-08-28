#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} DoublyLinkedList;

int init(DoublyLinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

int insertAtHead(DoublyLinkedList *list, int value) {
    Node *newNode = createNode(value);

    if(newNode == NULL) {
        return 0;
    }

    if(list->head == NULL) { /* then we are creating the very first node of DLL */
        list->head = newNode;
        return 0;
    }

    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;

    list->size++;

    return 1;
}

int insertAtEnd(DoublyLinkedList *list, int value) {
    Node *newNode = createNode(value);

    if(newNode == NULL) {
        return 0;
    }

    if(list->head == NULL) { /* then we are creating the very first node of DLL */
        list->head = newNode;
        return 0;
    }

    Node *currLastNode = list->head;

    while(currLastNode->next != NULL) {
        currLastNode = currLastNode->next;
    }

    currLastNode->next = newNode;
    newNode->prev = currLastNode;

    list->size++;
}

int insertAtIndex(DoublyLinkedList *list, int index, int value) {
    if(list == NULL || index < 0 || index > list->size) {
        return 0;
    }

    if(index == 0) {
        return insertAtHead(list, value);
    }

    if(index == list->size) {
        return insertAtEnd(list, value);
    }

    Node *newNode = createNode(value);

    if(newNode == NULL) {
        return 0;
    }

    Node *prevNode = list->head;
    int skips;
    for(skips = 1; skips <= index - 1; skips++) {
        prevNode = prevNode->next;
    }

    Node *nextNode = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nextNode;
    nextNode->prev = newNode;

    list->size++;

    return 1;
}

int deleteHeadNode(DoublyLinkedList *list, int *deletedValue) {
    if(list == NULL || list->head == NULL) {
        return 0;
    }

    *deletedValue = list->head->data;
    if(list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    }
    else {
        Node *temp = list->head->next;
        temp->prev = NULL;
        free(list->head);
        list->head = temp;
    }

    list->size--;

    return 1;
}

void sout(const DoublyLinkedList *list) {
    int i;
    if(list->size == 0) {
        printf("EMPTY LIST");
        return;
    }
    
    printf("NULL <--> ");
    
    Node *temp = list->head;
    while(temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int deleteAtIndex(DoublyLinkedList *list, int index, int *deletedValue) {
    if(list == NULL || index < 0 || index >= list->size) {
        return 0;
    }

    if(index == 0) {
        return deleteHeadNode(list, deleteAtIndex);
    }

    if(index == list->size - 1) {
        // return deleteNodeAtEnd(list, deletedValue);
    }

    int skips;
    Node *prevNode;
    for(skips = 1; skips <= index - 1; skips++) {
        prevNode = prevNode->next;
    }

    Node *nodeToDelete = prevNode->next;
    *deletedValue = nodeToDelete->data;
    Node *nextNode = nodeToDelete->next;
    free(nodeToDelete);
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    list->size--;

    return 1;
}

void freeList(DoublyLinkedList *list) {
    Node *currNode = list->head;
    Node *nextNode;
    while(currNode != NULL) {
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
    list->head = NULL;
    list->size = 0;
    return;
}

int main(void) {
    DoublyLinkedList list;
    if(init(&list) == 0){
        printf("Could not intialize DLL. Terminating the program ...");
        return 1;
    }
    insertAtHead(&list, 10);
    insertAtHead(&list, 20);
    insertAtHead(&list, 30);
    sout(&list);
    insertAtIndex(&list, 1, -10);
    sout(&list);
    int value;
    deleteHeadNode(&list, &value);
    sout(&list);
    return 0;
}