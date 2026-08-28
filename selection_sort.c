#include <stdio.h>

void selectionSort(int arr[], int n) {
    int temp;
    int i, j, smallestValueIndex;
    for(i = 0; i < n; i++) {
        smallestValueIndex = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[smallestValueIndex]) {
                smallestValueIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[smallestValueIndex];
        arr[smallestValueIndex] = temp;
    }
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}