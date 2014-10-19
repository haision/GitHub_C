#include <fcntl.h>
#include <stdio.h>

int main (int argc,char *argv){
	unsigned long int creatN,openN,offsetN,closeN;
	printf("%d\n",sizeof(creatN));
	char * content = "abcdefghijklm";
	creatN 	= creat("/usr/local/createfile",O_CREAT);
	openN 	= open("/usr/local/createfile",O_WRONLY);
	offsetN	= lseek(openN,6,SEEK_SET);
	write(openN,content,10);
	closeN	= close(openN);
}
