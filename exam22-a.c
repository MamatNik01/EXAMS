#include <stdio.h>
#include <string.h>

struct table_row
{
	char title[50];
	char mfg[100];
	short year;
	int price;
};

#define row_count 3
struct table_row row[row_count];

int main()
{
	strcpy(row[0].title, "Video Adapter");
	strcpy(row[0].mfg, "Nvidia");
	row[0].year = 2020;
	row[0].price = 40000;
	
	strcpy(row[1].title, "Hard Drive");
	strcpy(row[1].mfg, "Western Digital");
	row[1].year = 2019;
	row[1].price = 5000;
	
	strcpy(row[2].title, "Sound Card");
	strcpy(row[2].mfg, "Realtek");
	row[2].year = 2015;
	row[2].price = 1000;
	
	for(int i = 0; i < row_count; i++)
	printf("%s\t%s\t%d\t%d\n", row[i].title, row[i].mfg, row[i].year, row[i].price);
	
	char query[50];
	printf("query: ");
	fgets(query, 50, stdin);
	
	char *p = strchr(query, '\n');
	if(p != NULL) *p = 0;
	p = strchr(query, '\r');
	if(p != NULL) *p = 0;
	
	for(int i = 0; i < row_count; i++)
	if(strcmp(row[i].title, query) == 0) puts(row[i].mfg);
	
	return 0;
}