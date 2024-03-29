#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    FILE *f = fopen("extask03-out.txt", "w+");
    float x0, y0;
    do
    {
        printf("x0, y0 (x0 > 0 and y0 > 0): ");
        scanf("%f %f", &x0, &y0);
    }
    while (x0 <= 0 || y0 <= 0);
    float v0, a;
    do
    {
        printf("v0, a (v0 >= 0 and a >= 0): ");
        scanf("%f %f", &v0, &a);
    }
    while (v0 < 0 || a < 0);
    float ra = a * (float) M_PI / 180.0f;
    float v0x = cosf(ra) * v0;
    float v0y = sinf(ra) * v0;
#define g 9.8f
    fprintf(f, "formula calculations:\n");
    float d = v0y * v0y + 4.0f * g / 2.0f * y0;
    fprintf(f, "d = %f\n", d);
    float t1 = (-v0y - sqrtf(d)) / (2.0f * (-g / 2.0f));
    float t2 = (-v0y + sqrtf(d)) / (2.0f * (-g / 2.0f));
    fprintf(f, "t1 = %f, t2 = %f\n", t1, t2);
    float t = 0.0f;
    float x, y;
    float tprev = 0.0f;
    float tlast = 0.0f;
#define eps 0.01f
    fprintf(f, "change table t, x and y:\n");
    while (1)
    {
        x = x0 + v0x * t;
        y = y0 + v0y * t -  g* t * t / 2.0f;
        fprintf(f, "t = %f, x = %f, y = %f\n", t, x, y);
        if (y <= 0.0f) break;  
        tprev = t;
        t += eps;
        tlast = t;
    }
    fprintf(f, "selectable segment: \ntprev = %f, tlast = %f\n", tprev, tlast);
#define e 0.00001f
    float aa = tprev;
    float b = tlast;
    while (1) 
    {
        float c = (aa + b) * 0.5f; 
        float ya = y0 + v0y * aa -  g* aa * aa / 2.0f;; 
        float yc = y0 + v0y * c -  g* c * c / 2.0f;; 
        if (fabsf(yc) <= e) 
        {
            x = x0 + v0x * c;
            fprintf(f, "bisection method:\n");
            fprintf(f, "t1: %.6f\n", c);
            fprintf(f, "x1: %.6f\n", x);
            fprintf(f, "y1: %.6f\n", yc);
            break;
        }
        if (ya * yc < 0.0f) b = c; 
        else aa = c; 
    }
    fclose(f);
    return 0;
}
