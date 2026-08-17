#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 100

typedef struct {
    /* i am pointing it to last inserted value */
    int top; 
    /* static array, no need of pointer */
    int data[STACK_MAX_SIZE];
} Stack;

void init(Stack *st) {
    st->top = -1;
    return;
}

int isEmpty(const Stack *st) {
    if(st->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(const Stack *st) {
    if(st->top == (STACK_MAX_SIZE - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

int push(Stack *st, int value) {
    if(isFull(st) == 1) {
        return 0;
    }
    st->top++;
    st->data[st->top] = value;
    return 1;
}

int peek(Stack *st, int *peekValue) {
    if(isEmpty(st) == 1) {
        return 0;
    }
    *peekValue = st->data[st->top];
    return 1;
}

int pop(Stack *st, int *poppedValue) {
    if(isEmpty(st) == 1) {
        return 0;
    }
    *poppedValue = st->data[st->top];
    st->top--;
    return 1;
}

int clear(Stack *st) {
    st->top=-1;
    return 1;
}

int main(void) {
    Stack stack;
    
    /* init(stack); then the init function would receive a copy of the struct var, and this stack in main would remain unaffected */ 
    init(&stack);

    if(isEmpty(&stack) == 1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack has elements\n");
    }

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    int peekValue;
    if(peek(&stack, &peekValue) == 1) {
        printf("Peek value at top of stack: %d\n", peekValue);
    }
    else {
        printf("Stack empty, nothing to peek \n");
    }

    printf("TOP before pop %d\n", stack.top);

    int poppedValue;
    if(pop(&stack, &poppedValue) == 1) {
        printf("Popped value from top of stack: %d\n", poppedValue);
    }
    else {
        printf("Stack empty, nothing to pop() \n");
    }

    if(pop(&stack, &poppedValue) == 1) {
        printf("Popped value from top of stack: %d\n", poppedValue);
    }
    else {
        printf("Stack empty, nothing to pop() \n");
    }

    if(pop(&stack, &poppedValue) == 1) {
        printf("Popped value from top of stack: %d\n", poppedValue);
    }
    else {
        printf("Stack empty, nothing to pop() \n");
    }

    if(pop(&stack, &poppedValue) == 1) {
        printf("Popped value from top of stack: %d\n", poppedValue);
    }
    else {
        printf("Stack empty, nothing to pop() \n");
    }

    if(pop(&stack, &poppedValue) == 1) {
        printf("Popped value from top of stack: %d\n", poppedValue);
    }
    else {
        printf("Stack empty, nothing to pop() \n");
    }

    printf("TOP after pop %d\n", stack.top);

    if(peek(&stack, &peekValue) == 1) {
        printf("Peek value at top of stack: %d\n", peekValue);
    }
    else {
        printf("Stack empty, nothing to peek \n");
    }

    return 0;
}

