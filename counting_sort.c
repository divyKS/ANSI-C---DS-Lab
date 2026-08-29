#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a > b ? a : b)

void countingSort(int A[], int B[], int k, int n) {
    int i;
    /* k as an index should exist */
    int C[k + 1];

    for(i = 0; i < k + 1; i++) {
        C[i] = 0;
    }

    for(i = 0; i < n; i++) {
        C[A[i]]++;
    }

    for(i = 1; i < k + 1; i++) {
        C[i] = C[i] + C[i - 1];
    }

    /**
     * C = {2, 3, 3, 5}
     * idx  0  1  2  3
     * elements: 0 0 1      
     */

    /* RtL for stable algo */
    for(i = n - 1; i >= 0; i--) {
        /* this -1 below is needed otherwise we overflow by 1 index higher */
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main(void) {
    int i, n;
    int k = 0;
    int *A, *B;

    scanf("%d", &n);

    A = malloc(sizeof(int) * n);
    B = malloc(sizeof(int) * n);

    if(A == NULL || B == NULL) {
        free(A);
        free(B);
        return 1;
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        k = MAX(k, A[i]);
    }

    countingSort(A, B, k, n);

    for(i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }

    free(A);
    free(B);

    return 0;
}