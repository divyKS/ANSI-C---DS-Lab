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

int insertAtIndex(LinkedList *list, int index, int value) {
    if(list == NULL || index < 0 || index > list->size) {
        return 0;
    }

    if(index == 0) {
        return insertNodeAtHead(list, value);
    }

    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL) {
        return 0;
    }

    Node *temp = list->head;
    int skips;
    for(skips = 1; skips <= index - 1; skips++) {
        temp = temp->next;
    }

    // temp now points to the node after which this new node is to be inserted
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    list->size++;

    return 1;
}

int deleteNodeAtHead(LinkedList *list, int *deletedNodeValue) {
    if(list == NULL || list->head == NULL) {
        return 0;
    }

    Node* temp = list->head;
    *deletedNodeValue = temp->data;
    list->head = list->head->next;
    free(temp);
    list->size--;

    return 1;
}

int deleteLast(LinkedList *list, int *lastNodeValue) {
    if (list->head == NULL) {
        return 0;
    }

    if (list->head->next == NULL) {
        *lastNodeValue = list->head->data;

        free(list->head);

        list->head = NULL;
        list->size--;

        return 1;
    }

    Node *temp = list->head;

    while (temp != NULL && temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    Node *lastNode = temp->next;
    *lastNodeValue = temp->data;
    temp->next = NULL;
    free(lastNode);

    list->size--;

    return 1;
}

int deleteNodeAtIndex(LinkedList *list, int index, int *deletedValue) {
    if(list == NULL || index < 0 || index >= list->size) {
        return 0;
    }

    if(index == 0) {
        return deleteNodeAtHead(list, deletedValue);
    }

    Node *temp = list->head;
    int skips;
    for(skips = 1; skips <= index - 1; skips++) {
        temp = temp->next;
    }

    Node *deletedNode = temp->next;
    *deletedValue = deletedNode->data;
    temp->next = deletedNode->next;
    free(deletedNode);
    list->size--;

    return 1;
}

int updateValueAtIndex(LinkedList *list, int index, int value) {
    if (index < 0 || index >= list->size) {
        return 0;
    }

    Node *temp = list->head;

    int i;
    for (i = 0; i < index; i++) {
        temp = temp->next;
    }

    temp->data = value;

    return 1;
}

void freeList(LinkedList *list) {
    
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
    insertAtIndex(&list, 0, -10);
    insertAtIndex(&list, 3, 30);
    // if(insertAtIndex(&list, 10, 100) == 0) {
    //     printf("Could not insert at given position\n");
    // }
    int value;
    sout(&list);
    // deleteNodeAtHead(&list, &value);
    // deleteLast(&list, &value);
    deleteNodeAtIndex(&list, 1, &value);
    
    sout(&list);
}