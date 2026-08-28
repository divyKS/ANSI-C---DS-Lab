#include <stdio.h>

void quickSort(int arr[], int start, int end) {
    int i, j, temp;
    int pivot = arr[end];
    if(start >= end) {
        return;
    }

    for(i = start; i < end; ) {
        if(arr[i] >= pivot) { /* i is occurence of value greater than pivot */
            j = i + 1; /* finding and pointing to the nearest value smaller than pivot for the given i */
            while(j < end && arr[j] >= pivot) {
                j++;
            }
            /* j would not be pointing to smaller value */
            if(j == end) {
                break;
            }
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        else {
            i++;
        }
    }
    /* i points to a value bigger than pivot since we would have broken out of the if eventually */
    temp = arr[i];
    arr[i] = pivot;
    arr[end] = temp;
    /* i now points to pivot, and that is at its correct position */
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
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