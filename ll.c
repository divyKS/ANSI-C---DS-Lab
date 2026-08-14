#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next; // inside the definition, typedef is not available
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList; // although a single Node *head, will work perfectly fine, this maybe for augumentation later

void init(LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

int main(void) {
    LinkedList list;
    init(&list);
}