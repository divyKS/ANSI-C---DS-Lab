#include <stdio.h>

void shellSort(int arr[], int n) {
    int i, j, gap, newValueBeingInserted;
    for(gap = n / 2; gap >= 1; gap = gap / 2) { /* missed this, gap needs to stop at 1 not 0 */
        for(i = gap; i < n; i++) {
            newValueBeingInserted = arr[i];
            for(j = i - gap; j >= 0; j = j - gap) {
                if(newValueBeingInserted >= arr[j]) {
                    break;
                }
                else {
                    arr[j + gap] = arr[j];
                }
            }
            arr[j + gap] = newValueBeingInserted;
        }
    }
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    shellSort(arr, n);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}