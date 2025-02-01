#include <stdio.h>

typedef struct Person {
    char firstName[30];
    char lastName[30];
    int age;
    char job[30];
    struct Person* father;
} Person;

int main() {
    Person Jules; //Declaration
    Person PJules = {"Durand", "Patrice", 80, "Painting", NULL}; //Declaration and Initialization
    Jules = (Person){"Jules", "Durand", 27, "Engineering", &PJules}; //Initialization
    // strcpy(Jules.firstName, "newName") this if i need to change a string
    
    printf("The first name is: %s\n", Jules.firstName);
    printf("The last name is: %s\n", Jules.lastName);
    printf("The age is: %d\n", Jules.age);
    printf("The job is : %s\n", Jules.job);
    printf("The father's first name is: %s\n", Jules.father->lastName);

    return 0;
}