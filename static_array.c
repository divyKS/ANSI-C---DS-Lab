#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int linearSearch(int arr[], int size, int key);
int insertAtIndex(int arr[], int *size, int capacity, int index, int value);
int deleteAtIndex(int arr[], int *size, int index);
int maximum(int arr[], int size);
void reverseArray(int arr[], int size);



int main(void) {
    int arr[CAPACITY] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("The 4th element is = %d\n", *(arr + 3));
    printf("The 4th element address is = %d\n", (arr + 3));
    printf("The 4th element is = %d", *(&*arr + 3*sizeof(int)));
    return 0;
}