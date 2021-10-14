#include <stdio.h>
#include <string.h>
#include <ctype.h>
enum {IN, OUT};
int main (void)
{
    char s[256];
    fgets(s, 256, stdin);
    
    char *p = strchr(s, '\n');
    if (p != NULL) p[0] = '\0';
    
    size_t n = strlen(s);
    
    printf("len: %ld\n", n);
    
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ') m++;
        }
        printf("spcs: %d\n", m);
        
    int count = 0; // код на "4" и на "5"(работает частично)
    int state = IN;
    for (char *ch = s; *ch != '\0'; ch++)
    {
        switch (*ch) 
        {
            case '\n':
            case ' ':
                if (state == IN) 
                {
                    state = OUT;
                    printf("len word: %d\n", count);
                }
                count = 0;
                break;
            default:
                if (state == OUT)
                    *ch = toupper(*ch),
                    state = IN;
                count++;
                break;
        }
    }
    printf("%s", s); 
        return 0;
}