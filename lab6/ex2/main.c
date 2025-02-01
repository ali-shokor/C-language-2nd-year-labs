#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node* next;
} node;

typedef node* LINK;

int SearchVersion1(LINK head, int id) {
    LINK temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

LINK SearchVersion2(LINK head, int id) {
    LINK temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int Size(LINK head) {
    LINK temp = head;
    int count = 0;
     while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void InsertHead(node** head, int inputId) {
    LINK newNode = (LINK)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->id = inputId;
    newNode->next = *head;
    *head = newNode;
}

void InsertTail(node** head, int id) {
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->id = id;
    newNode->next = NULL;   

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int RemoveHead(node** list) {
    int removedId;
    if (*list == NULL) {
        printf("The list is empty.\n");
        return -1;
    }
    LINK temp = *list;
    removedId = temp->id;
    *list = temp->next;
    free(temp);
    return removedId;
}

int RemoveTail(node** list) {
    int removedID;
    if (*list == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    if ((*list)->next == NULL) {
        removedID = (*list)->id;
        free(*list);
        *list = NULL;
        return removedID;
    }
  
    LINK temp = *list;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    removedID = temp->next->id;
    free(temp->next);
    temp->next = NULL;
    return removedID;
}

int Insert(node** list, int inputID, int pos) {
    LINK newNode = (node*)malloc(sizeof(node));
    newNode->id = inputID;
    newNode->next = NULL;

    if(pos < 1 || pos > Size(*list) + 1) {
        printf("Invalid position.\n");
        free(newNode);
        return -1;
    }

    if (pos == 1) {
        newNode->next = *list;
        *list = newNode;
        return 0;
    }

    LINK temp = *list;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return 0;
}


int Remove(node** list, int pos) {
    if(pos < 1 || pos > Size(*list)) {
        printf("Invalid position.\n");
        return -1;
    }

    LINK temp = *list;
    if (pos == 1) {
        *list = temp->next;
        free(temp);
        return 0; 
    }

    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    LINK removed = temp->next;
    temp->next = temp->next->next;
    free(removed);
    return 0;
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
    LINK list = NULL;

    // Insert elements at the head and tail
    InsertHead(&list, 10);
    InsertHead(&list, 20);
    InsertTail(&list, 30);
    InsertTail(&list, 40);
    printf("List after inserts (head and tail):\n");
    PrintList(list);

    // Remove elements from the head and tail
    printf("\nRemoved head: %d\n", RemoveHead(&list));
    printf("Removed tail: %d\n", RemoveTail(&list));
    printf("List after removals (head and tail):\n");
    PrintList(list);

    // Insert at a specific position
    Insert(&list, 25, 2);
    printf("\nList after inserting 25 at position 2:\n");
    PrintList(list);

    // Remove from a specific position
    Remove(&list, 2);
    printf("\nList after removing node at position 2:\n");
    PrintList(list);

    // Search for a value in the list
    int searchId = 30;
    if (SearchVersion1(list, searchId)) {
        printf("\nFound node with id %d using SearchVersion1.\n", searchId);
    } else {
        printf("\nNode with id %d not found using SearchVersion1.\n", searchId);
    }

    LINK foundNode = SearchVersion2(list, searchId);
    if (foundNode != NULL) {
        printf("\nFound node with id %d using SearchVersion2.\n", searchId);
    } else {
        printf("\nNode with id %d not found using SearchVersion2.\n", searchId);
    }

    // Print final list size
    printf("\nSize of the list: %d\n", Size(list));

    return 0;
}