#include <stdio.h>
#include <string.h>

struct record
{
    char fio[32];
    char cat[48];
    char num[24];
    char inf[64];
};

#define row 3
struct record tab[row];

int main()
{
    for(int i = 0; i < row; i++)
    {
    printf("[record %d]\n", i);
    
    printf("fio: ");
    gets(tab[i].fio);
    
    printf("cat: ");
    gets(tab[i].cat);
    
    printf("num: ");
    gets(tab[i].num);
    
    printf("inf: ");
    gets(tab[i].inf);
    
    printf("\n");
}

for (int i = 0; i < row; i++)
{
printf("%s\t%s\t%s\t%s\n", tab[i].fio, tab[i].cat, tab[i].num, tab[i].inf);
}
printf("search fio: ");
char fio[32];
gets(fio);
printf("\n");

int n = 0;
for (int i = 0; i < row; i++)
{
    char *p = strtok(tab[i].fio, " ");
    if (strcmp(p, fio) == 0)
    {
        printf("num: %s\n", tab[i].num);
        printf("inf: %s\n", tab[i].inf);
        n++;
    }
    else if (n < 1)
    {
        printf("not found!");
    }
}
printf("search cat: ");
char cat[32];
gets(cat);
printf("\n");
int m = 0;
for (int i = 0; i < row; i++)
{
    char *q = strtok(tab[i].cat, " ");
    if (strcmp(q, cat) == 0)
    {
        printf("num: %s\n", tab[i].num);
        printf("inf: %s\n", tab[i].inf);
        m++;
    }
    else if (n < 1)
    {
        printf("not found!");
    }
}
    return 0;
}



