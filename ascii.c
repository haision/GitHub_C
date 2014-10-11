#include <stdio.h>
int main()
{
        int c1,c2;
        typeof (c1) c4,c5;
        char c3;
        c1 = 'a'-'A';
        c2 = 'b'-'B';
        c3 = 'c'-32;
        c4 = 'd'-'\0';		
	c5 = 'd'-'0';

        printf("c1 is %d and c2 is %d====c4 is %d\n",c1,c2,c4);
        printf("c3 is %d and %c,and c5 is %d\n",c3,c3,c5);
}

