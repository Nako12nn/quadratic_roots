#include <stdio.h>
#include <math.h>
#include <complex.h>

#define EPSILON 0.0000001

double get_discriminant(double a, double b, double c) 
{
    double discriminant = (b * b - 4 * a * c);
    return discriminant;
}

void get_root(double discriminant, double a, double b, double* first_root, double* second_root) 
{
    double sqrt_d = sqrt(discriminant);// don't use it twice or more, cause it's very heavy

    *first_root = (-b - sqrt_d) / (2 * a) + 0.0; // if result is -0.0 then +0.0 switch the sign to plus
    *second_root = (-b + sqrt_d) / (2 * a) + 0.0;
}

double complex get_complex_discriminant(double discriminant) 
{
    double disc_abs = fabs(discriminant);
    double complex complx_discr = sqrt(disc_abs) * I;
    return complx_discr;
}

void get_complex_root(double complex complx_disc, double a, double b, double complex* first_root, double complex* second_root)
{
    *first_root = (-b - complx_disc) / (2 * a) + 0.0;
    *second_root = (-b + complx_disc) / (2 * a) + 0.0;
}



int main() {

    printf("Enter coefficients a, b and c of equation.\nExample: ax^2 + bx + c\n");
    printf("The a must not be 0\n");

    double a = 0.0; 
    double b = 0.0; 
    double c = 0.0;
    char ch;

    if(scanf("%lf", &a) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if(fabs(a) < EPSILON ) {
        printf("a must not be 0\n");
        return 1;
    }

    if(scanf("%lf", &b) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if(scanf("%lf", &c) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    while(getchar() && ch != '\n'); // clean buffer

    double discriminant = get_discriminant(a, b, c);
    if(discriminant < -EPSILON) {
        double complex complex_disc = get_complex_discriminant(discriminant);
        double complex first_complx_root = 0.0;
        double complex second_complx_root = 0.0;

        get_complex_root(complex_disc, a, b, &first_complx_root, &second_complx_root);
        printf("Complex root Z1 = %.2f %+.2fi\n", creal(first_complx_root), cimag(first_complx_root));
        printf("Complex root Z2 = %.2f %+.2fi\n", creal(second_complx_root), cimag(second_complx_root));
    }                                // + forces to print the sign of num
    else if(fabs(discriminant) < EPSILON) {
        double first_root = 0.0;
        double second_root = 0.0;

        get_root(discriminant, a, b, &first_root, &second_root);
        printf("There is only one root: %.2f\n", first_root);
    }
    else {
        double first_root = 0.0;
        double second_root = 0.0;

        get_root(discriminant, a, b, &first_root, &second_root);    
        printf("X1 = %.2f\nX2 = %.2f\n", first_root, second_root);
    }
    
    return 0;
}
