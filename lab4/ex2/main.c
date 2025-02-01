#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int z;
    char name[30];
    char color[30];
} Point;

Point fill() {
    Point p;
    printf("Enter your x: ");
    scanf("%d", &p.x);
    printf("Enter your y: ");
    scanf("%d", &p.y);
    printf("Enter your z: ");
    scanf("%d", &p.z);
    printf("Enter your name: ");
    scanf("%s", p.name);
    printf("Enter your color: ");
    scanf("%s", p.color );
    return p;
}


int distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p2.y, 2) + pow(p2.z - p1.z, 2));
}

int checkLocatoin(Point p1, Point p2) {
    if(p1.x == p2.x && p1.y == p2.y && p1.z == p2.z) {
        printf("The points are equel\n");
    }
    else 
        printf("The points are not equel\n");
}

int main() {
    Point p1;
    Point p2;
    p1 = fill();
    p2 = fill();
    printf("The distance is %d\n", distance(p1, p2));
    checkLocatoin(p1, p2);
}


// typedef struct {
//     int x;
//     int y;
//     int z;
//     char name[30];
//     char color[30];
// } Point;

// void fill(Point *p) {
//     printf("Enter your x: ");
//     scanf("%d", &p->x);
//     printf("Enter your y: ");
//     scanf("%d", &p->y);
//     printf("Enter your z: ");
//     scanf("%d", &p->z);
//     printf("Enter your name: ");
//     scanf("%s", p->name);
//     printf("Enter your color: ");
//     scanf("%s", p->color);
// }

// double distance(Point *p1, Point *p2) {
//     return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
// }

// void checkLocatoin(Point *p1, Point *p2) {
//     if (p1->x == p2->x && p1->y == p2->y && p1->z == p2->z) {
//         printf("The points are equal\n");
//     } else {
//         printf("The points are not equal\n");
//     }
// }

// int main() {
//     Point p1, p2;
//     fill(&p1);  // Passing address of p1
//     fill(&p2);  // Passing address of p2
//     printf("The distance is %.2f\n", distance(&p1, &p2));
//     checkLocatoin(&p1, &p2);
//     return 0;
// }
