#include <stdio.h>

// Just practicing pointers
int main() {
    int i = 5;
    int j = 3;

    int *pi = &i;
    int *pj = &j;

    printf("%p\n", pi);
    printf("%p\n", pj);

    printf("%d\n", *pi);
    printf("%d\n", *pj);

    *pi = 7;

    pj = pi;
    printf("%d\n", *pj);

    *pi = 9;
    printf("%d\n", *pj);
}