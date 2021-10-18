#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x0, y0;
    printf("x0: ");
    scanf("%f", &x0);
    printf("y0: ");
    scanf("%f", &y0);
    
    float v0, a;
    printf("v0: ");
    scanf("%f", &v0);
    printf("a: ");
    scanf("%f", &a);
    
    float ra = a * (float)M_PI/180.0f;
    
    #define g 9.8f
    
    float v0x = cosf(ra) * v0;
    float v0y = sinf(ra) * v0;

    float d = v0y * v0y - 4.0f * g / 2.0f * y0;
    printf("d = %f\n", d);
    
    float t1 = (-v0y - sqrtf(d)) / 2.0f * (-g / 2.0f);
    float t2 = (-v0y + sqrtf(d)) / 2.0f * (-g / 2.0f);
    printf("t1 = %f, t2 = %f\n", t1, t2);
    
    float t = 0.0f;
    float x, y;
    
    #define eps 0.01f
    
    while(1)
    {
    float x = x0 + v0x * t;
    float y = y0 + v0y * t - g * t * t / 2.0f;
    
    printf("t = %f, x = %f, y = %f\n", t, x, y);
    
    if(y <=0.0f) break;
    
    t+=eps;
    
    }
    
    return 0;
}


