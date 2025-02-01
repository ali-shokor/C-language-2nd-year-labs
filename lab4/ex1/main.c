#include <stdio.h>

int main() {
    typedef struct {
        char firstName[30];
        char lastName[30];
        int age;
        char job[30];
    } Person;

    Person Jules;  
    printf("Enter your first name: ");
    scanf("%[^\n]", Jules.firstName);
    getchar();

    printf("Enter your last name: ");
    scanf("%[^\n]", Jules.lastName);
    getchar();

    printf("Enter your age: ");
    scanf("%d", &Jules.age);
    getchar();

    printf("Enter your job name: ");
    scanf("%[^\n]", Jules.job);


    printf("\nYour first name is: %s\n", Jules.firstName);
    printf("Your last name is: %s\n", Jules.lastName);
    printf("Your age is: %d\n", Jules.age);
    printf("Your job name is: %s\n", Jules.job);

    return 0;
}