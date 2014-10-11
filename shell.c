#include <stdlib.h>
#include <stdio.h>

int main(int argc,char * argv[])
{         
	char cmd[10];
	sprintf(cmd,"ls %s",argv[1]);
        system(cmd); 
        return 0;
}
