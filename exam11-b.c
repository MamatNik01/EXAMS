#include <stdio.h>
#include <stdlib.h>
int main()
{
    #define rows 25
    #define cols 5
    int tab[rows][cols];
    #define mark0 2
    #define mark1 5
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++)
            tab[y][x] = mark0 + rand() % (mark1 - mark0 + 1);
    float avg[cols];
    for (int x = 0; x < cols; x++)
    {
        int s = 0;
        for (int y = 0; y < rows; y++)
            s += tab[y][x];
        avg[x] = s / (float) rows;
    }
    printf("");
    for (int x = 0; x < cols; x++)
        printf("\t%d", x + 1);
    printf("\n");
    for (int y = 0; y < rows; y++)
    {
        printf("%d", y + 1);
        for (int x = 0; x < cols; x++)
            printf("\t%d", tab[y][x]);
        printf("\n");
    }
    for (int x = 0; x < cols; x++)
    printf("\t%.2f", avg[x]);
    printf("\n");
    printf("worst:");
    float min = avg[0];
    for (int x = 0; x < cols; x++)
        if (avg[x] < min) min = avg[0];
    for (int x = 0; x < cols; x++)
        if (min == avg[x]) printf("\n\%d subject with avg = %.2f", x+1, min);
    printf("\n");
    return 0;
}