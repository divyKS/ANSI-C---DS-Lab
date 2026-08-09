#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    
    printf("Length of dynamic array: ");
    scanf("%d", &n);

    int* newAges = malloc(n * sizeof(int));

    printf("Enter the values of the array:\n");

    int i; // ANSI C
    for(i = 0; i < n; i++) {
        scanf("%d", (newAges + i));
    }

    printf("Aweosome Work!\nHere are the contents: ");

    for(i = 0; i < n; i++) {
        printf("%d ", *(newAges + i));
    }

    free(newAges);
    newAges = NULL;
    
    return 0;
}