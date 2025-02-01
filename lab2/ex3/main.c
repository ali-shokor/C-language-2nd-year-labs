 #include <stdio.h>

 void Permute(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
 }

    int main() {
        int x = 5;
        int y = 3;
    
        printf("Before permutation: x = %d, y = %d\n", x, y);
        Permute(&x, &y);
        printf("After permutation: x = %d, y = %d\n", x, y);
    }  