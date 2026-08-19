#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Node {
    int data;
    struct Node *leftNode;
    struct Node *rightNode;
} Node;

typedef struct StackNode {
    /* pointer to the tree node, not copying the node in this */
    Node *data;
    /* to keep the stack connected, since not having array here */
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

/* this time creating without array, with only pointer to the next link and so on, like a linked list for simplicity */
typedef struct QueueNode {
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

/* STACK FUNCTIONS FOR ITERATIVE TRAVERSALS */

void initStack(Stack *stack) {
    stack->top = NULL;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, Node *node) {
    StackNode *newNode = malloc(sizeof(StackNode));

    if (newNode == NULL) {
        return;
    }

    newNode->data = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

Node *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    StackNode *temp = stack->top;
    Node *treeNode = temp->data;

    stack->top = stack->top->next;

    free(temp);

    return treeNode;
}

/* QUEUE FUNCTIONS FOR LEVEL ORDER AND CREATE BT */

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue(Queue *queue, Node *data) {
    QueueNode *newNode = malloc(sizeof(QueueNode));

    if (newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node *dequeue(Queue *queue) {
    if (isQueueEmpty(queue))
        return NULL;

    QueueNode *temp = queue->front;

    Node *data = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return data;
}

Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = data;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    return newNode;
}

Node *insertNode(Node *parent, int data, int isLeftChild) {
    if (parent == NULL) {
        return NULL;
    }

    Node *newNode = createNode(data);

    if (newNode == NULL) {
        return NULL;
    }

    if(isLeftChild == 1) {
        newNode->leftNode = parent->leftNode;
        parent->leftNode = newNode;
    }
    else {
        newNode->rightNode = parent->rightNode;
        parent->rightNode = newNode;
    }

    return newNode;
}

Node *searchForNode(Node *node, int key) {
    if (node == NULL) {
        return NULL;
    }

    if (node->data == key) {
        return node;
    }

    Node *result = searchForNode(node->leftNode, key);

    if (result != NULL) {
        return result;
    }

    result = searchForNode(node->rightNode, key);

    return result;
}

int findHeight(Node *node) {
    if(node == NULL) {
        return -1;
    }
    int leftHeight = findHeight(node->leftNode);
    int rightHeight = findHeight(node->rightNode);
    return 1 + MAX(leftHeight, rightHeight);
}

int findDepth(Node *node, int key, int currentDepth) {
    if(node == NULL) {
        return -1;
    }
    if(node->data == key) {
        return currentDepth;
    }
    int depth = findDepth(node->leftNode, key, currentDepth + 1);
    if(depth != -1) {
        return depth;
    }

    depth = findDepth(node->rightNode, key, currentDepth + 1);
    if(depth != -1) {
        return depth;
    }

    return -1; /* maybe change this */
}

/*recursive traversals*/
void preorder(Node *node) {
    if(node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorder(node->leftNode);
    preorder(node->rightNode);
}

void postorder(Node *node) {
    if(node == NULL) {
        return;
    }
    postorder(node->leftNode);
    postorder(node->rightNode);
    printf("%d ", node->data);
}

void inorder(Node *node) {
    if(node == NULL) {
        return;
    }
    inorder(node->leftNode);
    printf("%d ", node->data);
    inorder(node->rightNode);
}

/* iterative traversals */ 

void inorderIterative(Node *node) {
    Stack stack;
    initStack(&stack);

    Node *temp = node;

    while(temp != NULL || isEmpty(&stack)) {
        while(temp != NULL) {
            push(&stack, temp);
            temp = temp->leftNode;
        }
        temp = pop(&stack);
        printf("%d ", temp->data); 
        temp = temp->rightNode; /* just one right */
    }
}

int equalTrees(Node *a, Node *b) {
    if(a == NULL || b == NULL) {
        return 1;
    }
    
    if(a == NULL || b == NULL) {
        return 0;
    }
    
    int leftSubTreeOfBoth = equalTrees(a->leftNode, b->leftNode);
    if(leftSubTreeOfBoth == 0) {
        return 0;
    }

    int rightSubTreeOfBoth = equalTrees(a->rightNode, b->rightNode);
    if(rightSubTreeOfBoth == 0) {
        return 0;
    }

    return 1;
}

/* maybe other two iterative traversals also have to be done */

void levelOrder(Node *root) {
    Queue queue;

    if (root == NULL) {
        return;
    }

    initQueue(&queue);

    enqueue(&queue, root);

    while(!isQueueEmpty(&queue)) {

        Node *currentNode = dequeue(&queue);

        printf("%d ", currentNode->data);

        if (currentNode->leftNode != NULL)
            enqueue(&queue, currentNode->leftNode);

        if (currentNode->rightNode != NULL)
            enqueue(&queue, currentNode->rightNode);
    }
}

void clearTree(Node *a) {
    if(a == NULL) return;
    clearTree(a->leftNode);
    clearTree(a->rightNode);
    free(a);
}

int main(void) {
    Node *root = createNode(10);
    Node *node20 = insertNode(root, 20, 1);
    Node *node30 = insertNode(root, 30, 0);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Levelorder: ");
    levelOrder(root);
    printf("\n");

    int height = findHeight(root);
    printf("Height of tree: %d\n", height);

    return 0;
}