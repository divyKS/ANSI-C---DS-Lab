#include <stdio.h>
#include <stdlib.h>

#define MIN_CAPACITY 4

typedef struct {
    int front; // points to the first element
    int rear; // points to the index where the next element will be enqueued
    int *data;

    int size;
    int CAPACITY;
} Queue;

int init(Queue *queue) {
    int *temp = malloc(MIN_CAPACITY * sizeof(int));
    if(temp == NULL) {
        return 0;
    }
    queue->data = temp;
    queue->front = -1;
    queue->rear = 0;
    queue->CAPACITY = MIN_CAPACITY;
    return 1;
}

int isEmpty(const Queue *queue) {
    if(queue->size == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(const Queue *queue) {
    if(queue->size == queue->CAPACITY) {
        return 1;
    }
    else {
        return 0;
    }
}

int enqueue(Queue *queue, int value) {
    int i;
    if(queue == NULL) {
        return 0;
    }
    if(queue->size == queue->CAPACITY) {
        // resize queue and copy and clean the ordering
        int newCapacity = queue->CAPACITY * 2;
        int *temp = malloc(newCapacity * sizeof(int));
        if(temp == NULL) {
            return 0;
        }
        for(i = 0; i < queue->size; i++) {
            *(temp + i) = queue->data[(queue->front + i) % queue->CAPACITY];
        }
        free(queue->data);
        queue->data = temp;
        queue->front = 0;
        queue->rear = queue->size;
        queue->CAPACITY = newCapacity;
    }

    if(queue->front == -1) {
        queue->front = 0; // re-intialize now
    }
    
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->CAPACITY;
    queue->size++;
}

int dequeue(Queue *queue, int *dequedValue) {
    int i;
    if(queue == NULL) {
        return 0;
    }
    
    if(isEmpty(queue)) {
        return 0;
    }

    *dequedValue = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->CAPACITY;
    queue->size--;

    if(queue->size == 0) {
        queue->front = -1;
        queue->rear = 0;
    }

    if((queue->size != 0) && (queue->size <= queue->CAPACITY/4)) {
        int newCapacity = queue->CAPACITY/2;
        if(newCapacity < MIN_CAPACITY) {
            newCapacity = MIN_CAPACITY;
        }
        
        int *temp = malloc(newCapacity * sizeof(int));

        if(temp == NULL) {
            return 0;
        }

        for(i = 0; i < queue->size; i++) {
            *(temp + i) = queue->data[(queue->front + i) % queue->CAPACITY];
        }

        free(queue->data);
        queue->data = temp;
        queue->CAPACITY = newCapacity;
        queue->front = 0;
        queue->rear = queue->size;
    }

    return 1;
}

int peek(const Queue *queue, int *peekedValue) {
    if (isEmpty(queue)) {
        return 0;
    }

    *peekedValue = queue->data[queue->front];

    return 1;
}

void sout(const Queue *queue) {
    int i;
    if(queue == NULL) {
        return;
    }
    printf("[");
    for(i = 0; i < queue->size; i++) {
        printf("%d", queue->data[(queue->front + i) % queue->CAPACITY]);
        if(i <= (queue->size - 2)) {
            printf(", ");
        }
    }
    printf("]\n");
    return;
}

void clear(Queue *queue) {
    queue->front = -1;
    queue->rear = 0;
    queue->size = 0;
}

void destroy(Queue *queue) {
    free(queue->data);
    queue->data = NULL;
    queue->front = -1;
    queue->rear = 0;
    queue->size = 0;
    queue->CAPACITY = MIN_CAPACITY;
}

int main(void) {
    Queue queue;

    if(init(&queue) == 0) {
        printf("Queue could not be initialized. Terminating program.");
        return 1;
    }

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    sout(&queue);

    enqueue(&queue, 50);

    sout(&queue);

    destroy(&queue);

    return 0;
}
