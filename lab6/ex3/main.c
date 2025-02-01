#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node* next;
} node;

typedef node* LINK;

LINK toList(int arr[], int n) {
    LINK head = NULL;
    LINK tail = NULL;

    if (n == 0) {
        printf("Empty list.\n");
        return NULL;
    }
    head = (LINK)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    head->id = arr[0];
    head->next = NULL;
    tail = head;

    for (int i = 1; i < n; i++) {
        LINK newNode = (LINK)malloc(sizeof(node));
        newNode->id = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void toArray(LINK head, int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        arr[i] = head->id;
        LINK deletedNode = head;
        // if (temp-> next != NULL)
        head = head->next;
        free(deletedNode);
    }
}

void PrintList(LINK head) {
    LINK temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->id);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Creating a linked list from array:\n");
    LINK list = toList(arr, n);
    PrintList(list);

    int newArray[n];
    printf("Converting linked list back to array and freeing the list:\n");
    toArray(list, n, newArray);

    printf("Array contents:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", newArray[i]);
    }
    printf("\n");

    return 0;
}
