#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000
#define MIN_CAPACITY 4

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

int init(ArrayList *arr) { // receives pointer to the original struct being modified
    // should not free this, as we need the memory
    // and ptr itself will be destroyed after this function
    int *ptr = malloc(MIN_CAPACITY * sizeof(int));

    if(ptr == NULL) {
        return 0;
    }

    arr->size = 0;
    arr->capacity = MIN_CAPACITY;
    arr->data = ptr;    

    return 1;
}

void clear(ArrayList *arr) {
    if(arr == NULL) return;
    
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

// const => the function will not modify the struct anyhow by this pointer arr, only access fields
int getSize(const ArrayList *arr) {
    return arr->size;
}

int getCapacity(const ArrayList *arr) {
    return arr->capacity;
}

int isEmpty(const ArrayList *arr) {
    if(arr->size == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(const ArrayList *arr) {
    if(arr->size == arr->capacity) {
        return 1;
    }
    else {
        return 0;
    }
}

// answer will be returned in value, the function returns the success response
int getValueAtIndex(const ArrayList *arr, int index, int *value) {
    if(arr == NULL || value == NULL) {
        return 0;
    }

    if(index < 0 || index >= arr->size) {
        return 0;
    }

    *value = arr->data[index];

    return 1;
}

int updateValueAtIndex(const ArrayList *arr, int index, int value) {
    if(arr == NULL) {
        return 0;
    }

    if(index < 0 || index >= arr->size) {
        return 0;
    }

    arr->data[index] = value;

    return 1;
}

int insertAtIndex(ArrayList *arr, int index, int value) {
    if(arr == NULL) {
        return 0;
    }

    if(index < 0 || index > arr->size) {
        return 0;
    }

    if(arr->size >= arr->capacity) {
        int *temp = realloc(arr->data, arr->capacity * 2 * sizeof(int));
        if(temp == NULL) {
            return 0;
        }
        arr->data = temp;
        arr->capacity*=2; 
    }

    int i;
    for(i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = value;
    arr->size++;

    return 1;
}

int insert(ArrayList *arr, int value) {
    int res = insertAtIndex(arr, arr->size, value);
    return res;
}

int deleteAtIndex(ArrayList *arr, int index) {
    if(arr == NULL) {
        return 0;
    }

    if(index < 0 || index >= arr->size) {
        return 0;
    }

    int i;
    for(int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;
    
    if(arr->size <= (arr->capacity/4)) {
        int newCapacity = arr->capacity/2;
        if(newCapacity < MIN_CAPACITY) newCapacity = MIN_CAPACITY;
        int *temp = realloc(arr->data, newCapacity * sizeof(int));
        if(temp == NULL) {
            return 0;
        }
        arr->data = temp;
        arr->capacity = newCapacity;
    }

    return 1;
}

int searchInSortedArr(const ArrayList *arr, int target, int *targetIndex) {
    if(arr == NULL) {
        return 0;
    }

    int l = 0, r = arr->size - 1;
    int m = -1;
    
    while(l <= r) {
        m = l + (r - l)/2;
        if(arr->data[m] == target) {
            *targetIndex = m;
            return 1;
        }
        else if(arr->data[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    if(m == -1) {
        *targetIndex = -1;
    }

    return 1;
}

void sortByKeys(ArrayList *arr)
{
    int i, j;
    int key;

    if(arr == NULL) {
        return;
    }

    for(i = 0; i < arr->size; i++) {
        for(j = 0; j < arr->size - 1 - i; j++) {
            if(arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

void sout(const ArrayList *arr) {
    int i;
    if(arr == NULL) {
        return;
    }

    printf("[");

    for(i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if(i <= (arr->size - 2)) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(void) {
    ArrayList arr; // variable
    
    if(init(&arr) == 0) {
        printf("ArrayList could not be initialized.");
        return 1;
    };

    // int value;
    // if(getValueAtIndex(&arr, 4, &value) == 1) {
    //     printf("%d\n", value);
    // }

    insert(&arr, 3);
    insert(&arr, 2);
    insert(&arr, 4);

    sout(&arr);

    sortByKeys(&arr);

    sout(&arr);

    deleteAtIndex(&arr, 1);

    sout(&arr);

    insert(&arr, 10);
    insert(&arr, 11);
    insert(&arr, 12);
    insert(&arr, 13);
    insert(&arr, 14);
    insert(&arr, 15);
    insert(&arr, 16);

    updateValueAtIndex(&arr, arr.size - 1, -89);

    sout(&arr);

    clear(&arr);

    return 0;
}