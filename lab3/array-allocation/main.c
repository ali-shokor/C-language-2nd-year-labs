#include <stdio.h>

void fill(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]); // (arr + i)
    }
}

int largerElement(int* arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // *(arr + i)
        }
    }
    return max;
}

int main() {
    int size;
    printf("Enter the size of your array: ");
    scanf("%d", &size);

    int arr[size];
    fill(arr, size);
    printf("The largest element in the array is: %d\n", largerElement(arr, size));
}