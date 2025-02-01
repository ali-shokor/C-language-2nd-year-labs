// This art was done by the artist ali shokor

#include <stdio.h>
#include <string.h>

// First we define the structure of each major and university
typedef struct Major {
    char name[30];
    char nameOfDepartment[30];
    int numberOfStudents;
    int numberOfCredit;
    float cost;
    char headAdvicer[30];
} Major;

typedef struct University {
    char universityName[30];
    char universityAddress[30];
    Major majors[50];
    int numberOfMajors;
} University;

// Make both function create to take input from the user and store it in the main
Major createMajor( ){
    Major major;
    printf("Enter the name of the major: ");
    scanf("%s", major.name);
    printf("Enter the name of the department: ");
    scanf("%s", major.nameOfDepartment);
    printf("Enter the number of students: ");
    scanf("%d", &major.numberOfStudents);
    printf("Enter the number of credits: ");
    scanf("%d", &major.numberOfCredit);
    printf("Enter the cost: ");
    scanf("%f", &major.cost);
    printf("Enter the name of the head advisor: ");
    scanf("%s", major.headAdvicer);
    return major;
}

University createUniversity() {
    University university;
    printf("Enter the name of the university: ");
    scanf("%s", university.universityName);
    printf("Enter the address of the university: ");
    scanf("%s", university.universityAddress);
    university.numberOfMajors = 0;
    return university;
}

// Fucntion that use call by reference to add the user input major
void AddMajor(University* U, Major major) {
    if (U->numberOfMajors < 50) {
        U->majors[U->numberOfMajors] = major;
        U->numberOfMajors++;
    } else {
        printf("Can't find space for this major!\nTry later.");
    }
}

// Call by value to return the updated university wich is in the main
University UpdateMajor(char nameMajor[], University U, float newCost) {
    int temp = 0; // This is not required just to make the code somehow proffesional like me :p
    for (int i = 0; i < U.numberOfMajors; i++) {
        if (strcmp(U.majors[i].name, nameMajor) == 0) {
            U.majors[i].cost = newCost;
            printf("The new cost of %s is %.2f\n", nameMajor, newCost);
            temp = 1;
            break; // This break also not required but it's good practice
        }
    }
    if (!temp) printf("Major %s is not found\n", nameMajor);
    
    return U;
}


// Search for the user input major, nahhh it's simple 
void SearchMajor(University U, Major major) {
    int temp = 0; // This also is not required
    for (int i = 0; i < U.numberOfMajors; i++) {
        if (strcmp(U.majors[i].name, major.name) == 0){
            printf("The total cost of %s major is %.2f\n",major.name, U.majors[i].cost); // major.cost
            temp = 1;
            break; // Same for here
        }
    }
    if (!temp) printf("Major %s is not found", major.name);
}

// And here just gather the puzzle pieces
int main() {
    int n;
    char answer;
    printf("Enter the number majors that you have in your university: ");
    scanf("%d", &n);
    while ((getchar()) != '\n'); // Flush input buffer and dont ask me why
    // Just kidding when using scanf with %d, %f, or %c, the newline character (\n) remains in the buffer.
    // This causes problems with subsequent scanf calls, especially with %c or %s
    // So yeah!

    University university = createUniversity();

    for (int i = 0; i < n; i++) {
        Major major = createMajor();
        AddMajor(&university, major);
    }
    
    printf("Do you want to update an major? (y/n)");
    scanf(" %c", &answer);
   

    if (answer == 'y') {
        float newCost;
        char nameMajor[50];
        printf("What is the name of this major: ");
        scanf("%s", &nameMajor);
        printf("What is the new cost of this major: ");
        scanf("%f", &newCost);
        university = UpdateMajor(nameMajor, university, newCost);
    }

    printf("Do you want to search for an major? (y/n)");
    scanf(" %c", &answer);

    if (answer == 'y') {
        Major searchMajor;
        printf("What is the name of this major that you want to search: ");
        scanf("%s", searchMajor.name);
        SearchMajor(university, searchMajor);
    }

    // Now let us print the whole result
    printf("University: %s\nAddress: %s\nMajors:\n", university.universityName, university.universityAddress);
    for (int i = 0; i < university.numberOfMajors; i++) {
        Major m = university.majors[i];
        printf("  Major %d:\n", i + 1);
        printf("  Name: %s\n", m.name);
        printf("  Department: %s\n", m.nameOfDepartment);
        printf("  Students: %d\n", m.numberOfStudents);
        printf("  Credits: %d\n", m.numberOfCredit);
        printf("  Cost: %.2f\n", m.cost);
        printf("  Head Advisor: %s\n", m.headAdvicer);
    }

    // And this was everything for this excercise you'r welcome dear!
    return 0;
}