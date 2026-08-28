#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    for(i = 0; i < n; i++) {
        swapped = 0;
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swapped = 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if(swapped == 0) break;
    }
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}