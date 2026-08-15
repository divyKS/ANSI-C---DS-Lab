#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *leftNode;
    struct Node *rightNode;
} Node;

typedef struct {
    Node *root;
} BinaryTree;

int main(void) {
    BinaryTree tree;

    return 0;
}