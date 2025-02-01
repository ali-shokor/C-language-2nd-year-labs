#include <stdio.h>
#include <stdlib.h>

void allocating(int** p, int students, int courses) {
    for (int i = 0; i < students; i++) {
        p[i] = (int*)malloc(courses * sizeof(int));

        if (p[i] == NULL) {
            printf("No space in memory\n");
            exit(0);
        }

        printf("Enter grades for student %d:\n", i + 1);
        for (int j = 0; j < courses; j++) {
            scanf("%d", &p[i][j]);
        }
    }
}

void deAllocating(int** p, int students, int courses) {
    for (int i = 0; i < students; i++) {
        free(p[i]);
    }
    free(p);
}

int highestGrade(int** p, int students, int courses) {
    for (int i = 0; i < courses; i++) {
        int max = p[0][i];
        for (int j = 0; j < students; j++) {
            if (p[j][i] > max) {
                max = p[j][i];
            }
        }
        printf("The greatest grade in course %d is %d\n", i + 1, max);
    }
    return 0;

}

void avgCourse(int** p, int students, int courses, float* avg) {
    for (int i = 0; i < courses; i++) {
        int sum = 0;
        for (int j = 0; j < students; j++) {
            sum += p[j][i];
        }
        avg[i] = (float)sum / students;
        printf("The average of course %d is %.1f\n", i + 1, avg[i]);
    }
}

void avgStudent(int** p, int students, int courses) {
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < courses; j++) {
            sum += p[i][j];
        }
        printf("The average of student %d is %.2f\n", i + 1, (float)sum / courses);
    }
}

void countSuccedStudents(int** p, int students, int courses, float* avg) {
    int count = 0;
    for (int i = 0; i < courses; i++) {
        count = 0;
        for (int j = 0; j < students; j++) {
            if (p[j][i] >= avg[i]) {
                count++;
            }
        }
        printf("The number of students that have an grade grater than the average of course %d is %d\n", i + 1, count);
    }
    
   
}

void displayMatrix(int** p, int students, int courses) {
    printf("\nGrades Matrix:\n");
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < courses; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int students, courses;
    int **p;

    printf("Enter the number of students: ");
    scanf("%d", &students);
    printf("Enter the number of courses: ");
    scanf("%d", &courses);

    float *avgCourseArray = (float*)malloc(courses * sizeof(float));
    p = (int**)malloc(students * sizeof(int*));

    allocating(p, students, courses);
    highestGrade(p, students, courses);
    avgCourse(p, students, courses, avgCourseArray);
    avgStudent(p, students, courses);
    countSuccedStudents(p, students, courses, avgCourseArray);
    displayMatrix(p, students, courses);
    deAllocating(p, students, courses);

    return 0;
} 