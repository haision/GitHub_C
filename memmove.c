#include <string.h>
#include <stdio.h>

int main(void) 
{
    char dest[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    char *src = "******************************";
    
    printf("destination prior to memmove: %s\n", dest);
    memmove(dest, src, 26);
    printf("destination after memmove: %s\n", dest);
    memset(dest, 'a',10);
    puts(dest);
    return 0;
}

