#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <conio.h>

double f(double x)
{
    return -3.0f * cosf(x);
}

int main()
{
    double a, b;
    printf ("a, b: ");
    scanf("%lf %lf", &a, &b);
    
    double e;
    printf ("e: ");
    scanf("%lf", &e);

    while (1)
    {
        double c = (a + b) / 2.0;
        float fa = f(a);
        float fc = f(c);
        
        if (fabsf(fc) <= e)
        {
            printf("a: %.5f\n", a);
            printf("b: %.5f\n", b);
            printf("e: %.5f\n", e);
            printf("c: %.5f\n", c);
            printf("fa: %.5f\n", fa);
            printf("fc: %.5f\n", fc);
            printf("x: %.5f\n", c);
            printf("y: %.5f\n", fc);
            break;
        }
        
        if (fa * fc > 0.0f)
        a = c;
        else
        b = c;
    }
    FILE *file = fopen ("C:/c/exam07-c.txt", "w");
    while (1)
    {
        double c = (a + b) / 2.0;
        float fa = f(a);
        float fc = f(c);
        
        if (fabsf(fc) <= e)
        {
            fprintf(file, "a: %.5f\n", a);
            fprintf(file, "b: %.5f\n", b);
            fprintf(file, "e: %.5f\n", e);
            fprintf(file, "c: %.5f\n", c);
            fprintf(file, "fa: %.5f\n", fa);
            fprintf(file, "fc: %.5f\n", fc);
            fprintf(file, "x: %.5f\n", c);
            fprintf(file, "y: %.5f\n", fc);
            break;
        }
        if (fa * fc > 0.0f)
        a = c;
        else
        b = c;
    }
    fclose(file);
    return 0;
}