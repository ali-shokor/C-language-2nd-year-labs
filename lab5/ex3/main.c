#include <stdio.h>
#include <math.h>

typedef struct Poly {
    int degree;
    float coefficients[101];
} Poly;

Poly CreatePoly() {
    Poly p;
    printf("Enter the degree of the polynomial (<= 100): ");
    scanf("%d", &p.degree);
    printf("Enter the coefficients from degree 0 to degree %d:\n", p.degree);
    for (int i = 0; i <= p.degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%f", &p.coefficients[i]);
    }
    return p;
}

Poly SumPoly(Poly P1, Poly P2) {
    Poly P3;
    P3.degree = (P1.degree > P2.degree) ? P1.degree : P2.degree;

    for (int i = 0; i< P3.degree; i++) {
        P3.coefficients[i] = 0;  // Initialize coefficients
        if (i <= P1.degree) {
            P3.coefficients[i] += P1.coefficients[i];
        }
        if (i <= P2.degree) {
            P3.coefficients[i] += P2.coefficients[i];
        }
    }
    return P3;
}

void DerivePoly(Poly* p) {
    
    for (int i = 1; i <= p->degree; i++) {
        p->coefficients[i-1] = i * p->coefficients[i];
    }
    p->degree--;
    
}

float EvalPoly(Poly* P, float a) {
    float result = 0;
    for (int i = 0; i <= P->degree; i++) {
        result += P->coefficients[i] * pow(a, i);
    }
    return result;
}

int main() {
    Poly P1 = CreatePoly();
    Poly P2 = CreatePoly();
    
    printf("\nSum of the polynomials:\n");
    Poly sum = SumPoly(P1, P2);
    printf("Degree: %d\nCoefficients: ", sum.degree);
    for (int i = 0; i <= sum.degree; i++) {
        printf("%.2f ", sum.coefficients[i]);
    }
    printf("\n");
    
    DerivePoly(&P1);
    printf("\nDerivative of the first polynomial:\n");
    printf("Degree: %d\nCoefficients: ", P1.degree);
    for (int i = 0; i <= P1.degree; i++) {
        printf("%.2f ", P1.coefficients[i]);
    }
    printf("\n");
    
    float a;
    printf("\nEnter the value of a to evaluate the polynomial: ");
    scanf("%f", &a);
    float value = EvalPoly(&P2, a);
    printf("The value of the second polynomial at x = %.2f is %.2f\n", a, value);
    return 0;
}