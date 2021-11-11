#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

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
    return 0;
}