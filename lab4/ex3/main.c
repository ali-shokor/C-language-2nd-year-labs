// Note in this lab there are several ways are used but not all of them are important.
#include <stdio.h>
#include <string.h>


typedef struct {
    int id;
    char name[50];
    char department[50];
    int num_students;
    int num_credits;
    float cost_per_credit;
    char responsible_name[50];
} Degree;


void ReadDegrees(Degree Ldeg[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for degree %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &Ldeg[i].id);
        getchar(); // Clear buffer

        printf("Name: ");
        // scanf("%[^\n]", Ldeg[i].name);
        // getchar();
        fgets(Ldeg[i].name, sizeof(Ldeg[i].name), stdin);
        Ldeg[i].name[strcspn(Ldeg[i].name, "\n")] = '\0'; // Remove newline

        printf("Department: ");
        fgets(Ldeg[i].department, sizeof(Ldeg[i].department), stdin);
        Ldeg[i].department[strcspn(Ldeg[i].department, "\n")] = '\0'; // Remove newline

        printf("Number of students: ");
        scanf("%d", &Ldeg[i].num_students);

        printf("Number of credits: ");
        scanf("%d", &Ldeg[i].num_credits);

        printf("Cost per credit: ");
        scanf("%f", &Ldeg[i].cost_per_credit);
        getchar(); // Clear buffer

        printf("Responsible name: ");
        fgets(Ldeg[i].responsible_name, sizeof(Ldeg[i].responsible_name), stdin);
        Ldeg[i].responsible_name[strcspn(Ldeg[i].responsible_name, "\n")] = '\0'; // Remove newline
    }
}

void SearchDegree(Degree Ldeg[], int n, char degree_name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(Ldeg[i].name, degree_name) == 0) {
            printf("\nDegree found:\n");
            printf("ID: %d\n", Ldeg[i].id);
            printf("Name: %s\n", Ldeg[i].name);
            printf("Department: %s\n", Ldeg[i].department);
            printf("Number of students: %d\n", Ldeg[i].num_students);
            printf("Number of credits: %d\n", Ldeg[i].num_credits);
            printf("Cost per credit: %.2f\n", Ldeg[i].cost_per_credit);
            printf("Responsible name: %s\n", Ldeg[i].responsible_name);
            return;
        }
    }
    printf("\nDegree not found.\n");
}

void UpdateCost(Degree Ldeg[], int n, int id, float new_cost) {
    for (int i = 0; i < n; i++) {
        if (Ldeg[i].id == id) {
            Ldeg[i].cost_per_credit = new_cost;
            printf("\nCost updated successfully for degree ID %d.\n", id);
            return;
        }
    }
    printf("\nDegree with ID %d not found.\n", id);
}

void DisplayDegrees(Degree Ldeg[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nDegree %d:\n", i + 1);
        printf("ID: %d\n", Ldeg[i].id);
        printf("Name: %s\n", Ldeg[i].name);
        printf("Department: %s\n", Ldeg[i].department);
        printf("Number of students: %d\n", Ldeg[i].num_students);
        printf("Number of credits: %d\n", Ldeg[i].num_credits);
        printf("Cost per credit: %.2f\n", Ldeg[i].cost_per_credit);
        printf("Responsible name: %s\n", Ldeg[i].responsible_name);
    }
}

int main() {
    int n = 5;
    Degree Ldeg[100];

    printf("Enter information for %d degrees:\n", n);

    ReadDegrees(Ldeg, n);

    char search_name[50];
    printf("\nEnter the name of the degree to search: ");
    getchar(); // Clear buffer
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // Remove newline
    SearchDegree(Ldeg, n, search_name);

    int update_id;
    float new_cost;
    printf("\nEnter the ID of the degree to update its cost: ");
    scanf("%d", &update_id);
    printf("Enter the new cost per credit: ");
    scanf("%f", &new_cost);
    UpdateCost(Ldeg, n, update_id, new_cost);

    printf("\nUpdated degree information:\n");
    DisplayDegrees(Ldeg, n);

    return 0;
}