#include <stdio.h> //printf
#include <stdlib.h> //rand
#define days 31
int pressure[31];
#define p_min 740
#define p_max 780
#define p_norm 760
 
void sortP()
{
    int i;
    int ch,t;
    do
    {
        t = 0;
        for(i = 1;i < days;i++)
        {
            if(pressure[i] >= pressure[i-1]) t++;
            else
            {
                ch = pressure[i];
                pressure[i] = pressure[i-1];
                pressure[i-1] = ch;
            }
                
        }
    }while( t < 30);
}
int main()
{
    int i;
    for(i=0; i<days; i++)
    pressure[i] = p_min + rand() % (p_max - p_min + 1);
    printf("day\t pressure\n");
    for(i=0; i<days; i++)
    printf("%d\t %d\n", i + 1, pressure[i]);
 
    int cnt_below = 0;
    int cnt_above = 0;
    int cnt_exact = 0;
    for (i = 0; i < days; i++)
    {
        int v = pressure[i];
        if (v < p_norm) cnt_below++;
        else if(v > p_norm) cnt_above++;
        else cnt_exact++;
 
    }
    printf("below: %d\n", cnt_below);
    printf("above: %d\n", cnt_above);
    printf("exact: %d\n", cnt_exact);
    
    sortP();
    for(i=0; i<days; i++)
    printf("%d ", pressure[i]);
    return 0;
}