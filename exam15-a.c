#include <stdio.h>
#include <string.h>

struct record
{
    char os[32];
    int virt;
    int phy;
    int price;
};

#define row 3
struct record tab[row];

int main()
{
    char tmp[32];
    for(int i = 0; i < row; i++)
    {
    printf("[record %d]\n", i);
    
    printf("os: ");
    gets(tab[i].os);
    
    printf("virt: ");
    gets(tmp);
    tab[i].virt = atoi(tmp);
    
    printf("phy: ");
    gets(tmp);
    tab[i].phy = atoi(tmp);
    
    printf("price: ");
    gets(tmp);
    tab[i].price = atoi(tmp);
    
    printf("\n");
}

for (int i = 0; i < row; i++)
{
printf("%s\t%d\t%d\t%d\n", tab[i].os, tab[i].virt, tab[i].phy, tab[i].price);
}
char os[32];
printf("search os: ");
scanf("%s", os);
printf("\n");

for (int i = 0; i < row; i++)
{
    if (strcmp(tab[i].os, os) == 0)
    {
        printf("virt: %d\n", tab[i].virt);
        printf("phy: %d\n", tab[i].phy);
    }
}
    return 0;
}



