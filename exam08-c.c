#include <stdio.h>
#include <stdlib.h>

int main()
{
    #define months 12
    int salary[months];
    int salary_max = 0;
    int salary_min = 0;
    
    #define salary_low 1000
    #define salary_hight 5000
    
    for (int i = 0; i < months; i++)
    salary[i] = salary_low + rand() % (salary_hight - salary_low + 1);
    
    for (int i = 0; i < months; i++)
    printf("% 5d", (i + 1));
    printf("\n");
    
    for (int i = 0; i < months; i++)
    printf("% 5d", salary[i]);
    printf("\n");
    
    for (int i = 0; i < months; i++)
    {
        float tax = salary[i] * 0.02f;
        printf(" %4.1f", tax);
    }
    printf("\n");
    
    for (int i = 0; i < months; i++)
    if (salary[salary_max] < salary[i])
    {
        salary_max = i;
    }
    printf("salary_max %d\n", salary[salary_max]);
    
    for (int i = 0; i < months; i++)
    if (salary[salary_min] > salary[i])
    {
        salary_min = i;
    }
    printf("salary_min %d\n", salary[salary_min]);
    
    int year_sum = 0;
    for (int i = 0; i < months; i++)
    year_sum += salary[i];
    
    printf("year_sum = %d\n", year_sum);
    
    float year_avg = year_sum / (float) months;
    printf("year_avg = %.2f\n", year_avg);
    
    for (int i = 0; i < months; i++)
    {
    float month_dif = salary[i] - year_avg;
    printf("month_dif[%d] = %.2f\n", i+1, month_dif);
    }
    return 0;
}