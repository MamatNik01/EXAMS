#include <stdio.h>
#include <stdlib.h>
int main()
{
    #define rows 10
    #define cols 5
    int tab[rows][cols];
    #define mark0 1
    #define mark1 10
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            tab[y][x] = mark0 + rand() % (mark1 - mark0 + 1);
    float avg[rows];
    for (int y = 0; y < rows; y++)
    {
        int s = 0;
        for (int x = 0; x < cols; x++)
            s += tab[y][x];
        avg[y] = s / (float) cols;
    }
    printf("");
    for (int x = 0; x < cols; x++)
        printf("\t%d", x + 1);
    printf("\t\n");
    float max = avg[0];
    int max_n = 0;
    for (int y = 0; y < rows; y++)
    {
        printf("", y + 1);
        for (int x = 0; x < cols; x++)            
        printf("\t%d", tab[y][x]);
        if (avg[y] > max)
        {
            max = avg[y];
            max_n = y + 1;
        }
        printf("\t\n", avg[y]);
    }
    printf("max_avg: %.1f. The best sportsmen is %d!\n", max, max_n);
    return 0;
}