#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node* next;
} node;

int main() {
    node a, b, c;
    printf("Enter your id of a: ");
    scanf("%d", &a.id);
    printf("Enter your id of b: ");
    scanf("%d", &b.id);
    printf("Enter your id of c: ");
    scanf("%d", &c.id);

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    printf("The value of a is %d and the value of b is %d and the value of c is %d\n", a.id, a.next->id, a.next->next->id);
    return 0;
}