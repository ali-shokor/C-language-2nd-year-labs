#include <stdio.h>

int main() {
   float arr[] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

   float *nPtr;

   for (int i = 0; i < 10; i++) {
       printf("%.1f\n", arr[i]);
   }

   nPtr = &arr[0];
   nPtr = arr;

   nPtr = &arr[3];
    printf("%.1f\n", *nPtr);

    nPtr = arr;
    nPtr = arr + 8;

    printf("%.1f\n", *nPtr);

    nPtr = &arr[5];
    printf("%.1f\n", *(nPtr-4));
}