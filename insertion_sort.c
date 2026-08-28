#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, newValueToBeInserted;
    for(i = 1; i < n; i++) {
        newValueToBeInserted = arr[i];
        for(j = i - 1; j >= 0; j--) {
            if(newValueToBeInserted >= arr[j]) {
                break;
            }
            else {
                arr[j + 1] = arr[j];
            }
        }
        arr[j + 1] = newValueToBeInserted;
    }
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
