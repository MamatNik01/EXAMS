#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x0, y0;
    do
    {
        printf("x0, y0 (if x0 > 0 and y0 > 0): ");
        scanf("%f %f", &x0, &y0);
    }
    while (x0 <= 0 || y0 <= 0);
    float v0, a;
    do
    {
        printf("v0, a (if v0 >= 0 and a >= 0): ");
        scanf("%f %f", &v0, &a);
    }
    while (v0 < 0 || a < 0);
    float ra = a * (float) M_PI / 180.0f;
    float v0x = cosf(ra) * v0;
    float v0y = sinf(ra) * v0;
#define g 9.8f
    float d = v0y * v0y + 4.0f * g / 2.0f * y0;
    printf("d: %f\n", d);
    float t1 = (-v0y - sqrtf(d)) / (2.0f * (-g / 2.0f));
    float t2 = (-v0y + sqrtf(d)) / (2.0f * (-g / 2.0f));
    printf("t1: %f, t2: %f\n", t1, t2);
    float t = 0.0f;
    float x, y;
#define eps 0.01f
    while (1)
    {
        x = x0 + v0x * t;
        y = y0 + v0y * t -  g* t * t / 2.0f;
        if (y <= 0.0f) break;        
        t += eps;       
    }
    printf("t: %f, x: %f, y: %f\n", t, x, y);
    return 0;
}