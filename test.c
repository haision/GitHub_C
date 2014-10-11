#include <stdio.h>

int a;
int b;
char *p="1111:w";

int main(void){
	int i;
	int *q =NULL;
	//*q = 0;
	q =&i;
	*q = 12;
	printf("%d,%x\n",a,&a);
	printf("p addr:%x\n",p);
	printf("q addr:%x\n",q);
	printf("*q val:%d\n",*q);
	printf("i val:%d\n",i);
	printf("&i addr:%x\n",&i);

	printf("sizeof p:%d\n",sizeof(p));
	printf("sizeof *p:%d\n",sizeof(*p));
	
	fprintf(stdout, "%s, %s %s, %s:%s\n","weekday", "month", "day", "hour", "min");

	return 0;
}
