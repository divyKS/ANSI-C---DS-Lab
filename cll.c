#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct {
    Node *head;
    Node *tail;
    int size;
} CircularLinkedList;

void init(CircularLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int isEmpty(const CircularLinkedList *list) {
    if(list->size == 0) {
        return 1;
    }
    return 0;
}

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

int insertNodeAtHead(CircularLinkedList *list, int value) {
    Node *newNode = createNode(value);

    if (newNode == NULL) {
        return 0;
    }

    if (list->head == NULL) { /* list was empty till now */
        list->head = newNode;
        list->tail = newNode;        
        list->head->next = list->head; /* a sigle node will point to itself */
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = list->head;
    }

    list->size++;

    return 1;
}

int insertNodeAtTail(CircularLinkedList *list, int value) {
    Node *newNode = createNode(value);

    if (newNode == NULL) {
        return 0;
    }

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        list->head->next = list->head;
    } else {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;

    return 1;
}

int insertNodeAtIndex(CircularLinkedList *list, int index, int value) {
    if (list == NULL || index < 0 || index > list->size) {
        return 0;
    }

    if (index == 0) {
        return insertNodeAtHead(list, value);
    }

    if (index == list->size) {
        return insertNodeAtTail(list, value);
    }

    Node *newNode = createNode(value);

    if (newNode == NULL) {
        return 0;
    }

    Node *prevNode = list->head;

    int skips;
    for (skips = 1; skips <= index - 1; skips++) {
        prevNode = prevNode->next;
    }

    Node *nextNode = prevNode->next;
    newNode->next = nextNode;
    prevNode->next = newNode;

    list->size++;

    return 1;
}

int deleteNodeAtHead(CircularLinkedList *list, int *deletedValue) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }

    Node *temp = list->head;

    *deletedValue = list->head->data;

    if (list->head == list->tail) { /* single node CLL */
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->tail->next = list->head;
    }

    free(temp);

    list->size--;

    return 1;
}

int deleteNodeAtTail(CircularLinkedList *list, int *deletedValue) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }
    
    if (list->head == list->tail) {
        Node *temp = list->head;
        *deletedValue = list->head->data;
        list->head = NULL;
        list->tail = NULL;
        free(temp);
    }
    else {
        Node *secondLastNode = list->head;
    
        while (secondLastNode->next != list->tail) {
            secondLastNode = secondLastNode->next;
        }
    
        Node *temp = list->tail;
        *deletedValue = temp->data;
        secondLastNode->next = list->head;
        list->tail = secondLastNode;
    
        free(temp);
    }

    list->size--;

    return 1;
}

int deleteNodeAtIndex(CircularLinkedList *list, int index, int *deletedValue) {
    if (list == NULL || index < 0 || index >= list->size) {
        return 0;
    }

    if (index == 0) {
        return deleteNodeAtHead(list, deletedValue);
    }

    if (index == list->size - 1) {
        return deleteNodeAtTail(list, deletedValue);
    }

    int skips;
    Node *prevNode = list->head;
    for (skips = 1; skips <= index - 1; skips++) {
        prevNode = prevNode->next;
    }

    Node *nodeToBeDeleted = prevNode->next;
    *deletedValue = nodeToBeDeleted->data;

    prevNode->next = nodeToBeDeleted->next;
    free(nodeToBeDeleted);

    list->size--;

    return 1;
}

void sout(const CircularLinkedList *list) {
    Node *temp = list->head;
    int i;
    for(i = 1; i <= list->size; i++) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("HEAD\n");
}

void clear(CircularLinkedList *list) {
    int i;
    Node *currentNode, *nextNode;

    currentNode = list->head;

    for (i = 0; i < list->size; i++) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int main(void) {
    CircularLinkedList list;
    init(&list);
    insertNodeAtHead(&list, 20);
    insertNodeAtHead(&list, 10);
    insertNodeAtTail(&list, 40);
    insertNodeAtIndex(&list, 2, 30);
    sout(&list);
    int value;
    deleteNodeAtHead(&list, &value);
    sout(&list);
    deleteNodeAtHead(&list, &value);
    sout(&list);
    deleteNodeAtIndex(&list, 1, &value);
    sout(&list);
    clear(&list);
    return 0;
}

