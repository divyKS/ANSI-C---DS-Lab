#include <stdio.h>

void quickSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }
    
    int i, j, temp;
    int pivot = arr[end];

    i = start - 1;
    for(j = start; j < end; j++) {
        if(arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    quickSort(arr, start, (i + 1) - 1);
    quickSort(arr, (i + 1) + 1, end);
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* start and end are both inclusive for my implementation */
    quickSort(arr, 0, n - 1);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}