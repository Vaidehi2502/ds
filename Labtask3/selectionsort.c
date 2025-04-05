#include <stdio.h>

void SelectSort(int *A, int n) {
    int i, j, min, max, temp;

    for (i = 0; i < n / 2; i++) {
        min = i;
        max = i;

        for (j = i + 1; j < n - i; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
            if (A[j] > A[max]) {
                max = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;

        // If the maximum element was swapped, update its index
        if (max == i) {
            max = min;
        }
        temp = A[n - i - 1];
        A[n - i - 1] = A[max];
        A[max] = temp;
    }
}

void printAay(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {64, 25, 12, 22, 11, 90, 34, 78};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original Aay: \n");
    printAay(A, n);

    SelectSort(A, n);

    printf("Sorted Aay: \n");
    printAay(A, n);

    return 0;
}
