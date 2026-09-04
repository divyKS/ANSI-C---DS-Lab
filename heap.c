#include<stdio.h>
#include<stdlib.h>

#define MAX 32767
#define MIN -32766

typedef struct {
    int *arr;
    int size;
    int CAPACITY;
} MaxHeap;

void heapify(MaxHeap *pq, int index) {
    int temp;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    
    if(leftChildIndex < pq->size && pq->arr[leftChildIndex] > pq->arr[index]) {
        temp = pq->arr[leftChildIndex];
        pq->arr[leftChildIndex] = pq->arr[index];
        pq->arr[index] = temp;
        heapify(pq, leftChildIndex);
        return;
    }

    if(rightChildIndex < pq->size && pq->arr[rightChildIndex] > pq->arr[index]) {
        temp = pq->arr[rightChildIndex];
        pq->arr[rightChildIndex] = pq->arr[index];
        pq->arr[index] = temp;
        heapify(pq, rightChildIndex);
        return;
    }
}

void init(MaxHeap *pq, int *inputArr, int n) {
    int i;
    pq->arr = malloc(sizeof(int) * n);

    if(pq->arr == NULL) {
        printf("COULD NOT INIT PQ");
        return;
    }
    
    pq->size = n;
    pq->CAPACITY = n;
    
    for (i = 0; i < n; i++) {
        pq->arr[i] = inputArr[i];
    }

    for (i = (n / 2) - 1; i >= 0; i--) {
        heapify(pq, i);
    }
}

int getMax(MaxHeap *pq) {
    if(pq->size > 0) {
        return pq->arr[0];
    }
    else {
        return -1;
    }
}

int extractMax(MaxHeap *pq) {
    if(pq->size == 0) {
        return -1;
    }

    int maxKey = pq->arr[0];
    int lastEleIndex = pq->size - 1;
    
    pq->size--;
    
    if(pq->size == 0) {
        return;
    }

    pq->arr[0] = pq->arr[lastEleIndex];
    heapify(pq, 0);

    return maxKey;
}

void increaseKey(MaxHeap *pq, int indexOfKeyToIncrease, int newKey) {
    /* will sort of heapify up inside downwards */
    int i = indexOfKeyToIncrease;
    int parentIndex, temp;
    
    pq->arr[indexOfKeyToIncrease] = newKey;


    while(i > 0) {
        parentIndex = (i - 1) / 2;
        if(pq->arr[parentIndex] >= pq->arr[i]) {
            break;
        }
        temp = pq->arr[i];
        pq->arr[i] = pq->arr[parentIndex];
        pq->arr[parentIndex] = temp;
        i = parentIndex;
    }
}

void insertNewKey(MaxHeap *pq, int newKey) {
    if(pq->size >= pq->CAPACITY) {
        printf("NO SPACE TO ADD ANOTHER KEY");
        return;
    }
    pq->arr[pq->size] = MIN;
    pq->size++;
    increaseKey(pq, pq->size - 1, newKey);
}

void deleteKey(MaxHeap *pq, int indexOfKeyToBeDeleted) {
    increaseKey(pq, indexOfKeyToBeDeleted, MAX);
    extractMax(pq);
    return;
}

void printHeap(MaxHeap *pq) {
    printf("TOP OF HEAP: %d", getMax(pq));
    printf("\n");
}

int main(void) {
    MaxHeap pq;
    int n = 5;
    int arr[] = {3,4,2,1,5};

    init(&pq, arr, n);
    printHeap(&pq);
}