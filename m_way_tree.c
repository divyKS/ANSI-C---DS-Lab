#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *parent;
    struct Node *leftChild; /*first left child*/
    struct Node *rightSibling;
} Node;

int main(void) {
    return 0;
}