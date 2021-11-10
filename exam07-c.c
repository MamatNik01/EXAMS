#include <stdio.h>
#include <stdlib.h>
#define mmin 2
#define mmax 5
#define mpas 4.6f

int main()
{
    int n;
    int *mark;
    int i;
    mark = (int *) malloc(n * sizeof(int));
    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &mark[i]);
    }
    for (i = 0; i < n; i++)
    {
    printf("%d ", mark[i]);
    }
    getchar();
    printf("\n");
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    sum += mark[i];
    
    float avg = (float) sum / (float) n;
    
    printf("avg: %.1f\n", avg);
    if (avg >= mpas)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}