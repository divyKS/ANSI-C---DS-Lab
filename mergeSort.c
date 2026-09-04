#include <stdio.h>
#include <stdlib.h>

#define MAX 32767

/* l and r are both inclusive indices */
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    
    /* the one more extra 1 for SENTINEL */
    int leftArrSize = m - l + 1 + 1;
    int rightArrSize = r - m + 1;

    int *leftArr = malloc(sizeof(int) * leftArrSize);
    int *rightArr = malloc(sizeof(int) * rightArrSize);

    for (i = 0; i < leftArrSize - 1; i++) {
        leftArr[i] = arr[l + i];
    }
    leftArr[i] = MAX;

    for (j = 0; j < rightArrSize - 1; j++) {
        rightArr[j] = arr[m + 1 + j];
    }
    rightArr[j] = MAX;

    i = 0;
    j = 0;

    for (k = l; k <= r; k++) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int l, int r) {
    if(l >= r) return; /* wrong range or single element */
    
    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
