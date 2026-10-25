#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void doubleArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(arr + i) * 2;
    }
}

int main() {
    int x = 10, y = 20;
    int numbers[5] = {1, 2, 3, 4, 5};
    int *ptr = numbers; // ptr points to the first element of numbers

    // 1. Basic Pointer & Dereferencing
    printf("--- Basic Pointer ---\n");
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void *)&x);
    printf("Value via pointer: %d\n\n", *(&x));

    // 2. Swapping via Pointers
    printf("--- Swap Function ---\n");
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap:  x = %d, y = %d\n\n", x, y);

    // 3. Pointer Arithmetic with Arrays
    printf("--- Array Traversal via Pointer Arithmetic ---\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: value = %d, address = %p\n", i, *(ptr + i), (void *)(ptr + i));
    }

    // 4. Modifying Array via Pointer Function
    doubleArray(numbers, 5);
    printf("\n--- Array After doubleArray() ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}