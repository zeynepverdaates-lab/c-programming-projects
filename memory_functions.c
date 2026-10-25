#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, new_size;
    printf("How many elements would you like to create for the array: ");
    scanf("%d", &n);

    int* arr = (int*)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("How many elements would you like to create for the array: ");
    scanf("%d", &new_size);

    arr = (int*)realloc(arr, new_size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = n; i < new_size; i++) {
        arr[i] = 0;
    }

    printf("Array after realloc: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}