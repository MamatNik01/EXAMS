#include <stdio.h>
#include <stdlib.h>

#define mmin 2
#define mmax 5

#define mpas 4.6f

int main()
{
    int n;
    int *mark;
    
    printf("n: ");
    scanf("%d", &n);
    
    mark = (int *) malloc(n * sizeof(int));
    
    printf("arr: ");
    for (int i = 0; i < n; i++)
    {
        mark[i] = mmin + rand() % (mmax - mmin + 1);
        printf("%d ", mark[i]);
    }
    printf("\n");
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    sum += mark[i];
    
    float avg = (float) sum / (float) n;
    
    printf("avg: %.1f\n", avg);
    if (avg > mpas)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}