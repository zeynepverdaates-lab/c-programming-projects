#include <stdio.h>

int numbers[7];
int i;

void sortIt();

int main()
{
    printf("Enter array numbers:");
    for (i = 0; i < 7; i++) {
        scanf("%d", &numbers[i]);
    }

    sortIt();

    printf("\nSorted Order: ");
    for (i = 0; i < 7; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

void sortIt() {
    int j, reserve;
    for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 7; j++) {
            if (numbers[j] < numbers[i]) {
                reserve = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = reserve;
            }
        }
    }
}