#include <stdio.h>
#include <string.h>

struct record
{
    int acc;
    char fio[32];
    float sum;
    int prc;
    float res;
};

#define row 3
struct record tab[row];

int main()
{
    char tmp[32];
    for(int i = 0; i < row; i++)
    {
    printf("[record %d]\n", i);
    
    printf("acc: ");
    gets(tmp);
    tab[i].acc = atoi(tmp);
    
    printf("fio: ");
    gets(tab[i].fio);
    
    printf("sum: ");
    gets(tmp);
    tab[i].sum = atoi(tmp);
    
    printf("%%: ");
    gets(tmp);
    tab[i].prc = atoi(tmp);
    
    printf("\n");
}

for (int i = 0; i < row; i++)
{
    tab[i].res = tab[i].sum + (tab[i].sum * tab[i].prc / 100.0f) / 12.0f;
}


for (int i = 0; i < row; i++)
{
printf("%d\t%s\t%.2f\t%d\t%.2f\n", tab[i].acc, tab[i].fio, tab[i].sum, tab[i].prc, tab[i].res);
}
return 0;
}


