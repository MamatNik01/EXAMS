#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define days 31
    float coeff[days];
    #define coeff_lo 10.0f
    #define coeff_hi 50.0f
    for (int i = 0; i < days; i++)
    coeff[i] = coeff_lo + (coeff_hi - coeff_lo) * (rand()%100)/(100*0.99);
    
    for (int i = 0; i < days; i++)
    {
        printf("% 2.2f", coeff[i]);
        if(i % 7 == 6)
        {
            printf("\n");
        }
    }
    
    if(days % 7 > 0)
    {
        printf("\n");
    }
    
    float cmin = coeff_hi;
    float cmax = coeff_lo;
    for (int i = 0; i < days; i++)
    {
        if (coeff[i] < cmin)
        {
            cmin = coeff[i];
        }
        if (coeff[i] > cmax)
        {
            cmax = coeff[i];
        }
    }
    
    printf("%.2f\n", cmin);
    printf("%.2f\n", cmax);
    
    return 0;
}
