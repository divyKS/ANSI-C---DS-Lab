#include <stdio.h>
#include <stdlib.h>

#define ROWS 2 
#define COLUMNS 3 

void sumElements(int arr[][3], int r) {
    int sum = 0;
    int i, j;
    
    for(i = 0; i < r; i++) {
        for(j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }

    printf("Sum of elements: %d", sum);
    return;
}

int main(void) {
    int marks[2][3] = {
        {10, 6, 9},
        {8, 7, 10}
    };
    
    int counts[ROWS][COLUMNS];

    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            scanf("%d", &counts[i][j]);
        }
    }

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%4d ", counts[i][j]);
        }
        printf("\n");
    }

    sumElements(counts, ROWS);

    return 0;
}