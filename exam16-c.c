#include <stdio.h>
struct record
{
    char drug_name[64];
    char indications[64];
    int exp_years, mfg_year;
};
#define n 3
struct record row[n];
int main()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d", 
            row[i].drug_name, row[i].indications,
            &row[i].exp_years, &row[i].mfg_year);
    }
    printf("drug_name\tindications\texp_years\tmfg_year\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%s\t\t%d\t\t%d\n", 
            row[i].drug_name, row[i].indications,
            row[i].exp_years, row[i].mfg_year);
    }
    FILE *f = fopen("extask16-out.txt", "w+");
    printf("drug_name\tindications\texp_years\tmfg_year\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s\t\t%s\t\t%d\t\t%d\n", 
            row[i].drug_name, row[i].indications,
            row[i].exp_years, row[i].mfg_year);
    }
    fclose(f);
    FILE *f11 = fopen("extask16-out.raw", "wb+");
    fwrite(row, sizeof(struct record), n, f11);   
    fclose(f11);
    return 0;
}