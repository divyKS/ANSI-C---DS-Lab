#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next; // inside the definition, typedef is not available, also need to have the struct tag so that it can self reference
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList; // although a single Node *head, will work perfectly fine, this maybe for augumentation later

void init(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

int insertNode(LinkedList *list, int value) {
    Node *newNode = malloc(sizeof(Node));
    // typecasting to (Node *) before the malloc is not needed here, that is needed for C++
    // can also do malloc(sizeof(*newNode)) so that if on the LHS the type of newNode is changed, it automatically gets adjusted instead of us doing that on the RHS too
    if(newNode == NULL) {
        return 0;
    }
    
    newNode->data = value;
    newNode->next = NULL;

    if(list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node *temp = list->head;
        
        while(temp != NULL && temp->next != NULL) {
            temp = temp->next;
        }
    
        temp->next = newNode;
    }

    list->size++;
    
    return 1;
}

int insertNodeAtHead(LinkedList *list, int value) {
    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL) {
        return 0;
    }

    newNode->data = value;
    newNode->next = list->head;

    list->head = newNode;
    list->size++;
    
    return 1;
}

void sout(const LinkedList *list) {
    Node *temp = list->head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main(void) {
    LinkedList list;
    init(&list);
    insertNodeAtHead(&list, 10);
    insertNode(&list, 20);
    sout(&list);
}