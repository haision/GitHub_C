#include <stdio.h>

int main(void){
	int a[10]={11,22,33,44,55,66,77,88,99,100};
	int *pa = &a[0];
	
	printf("&a[10]:	%x\n",&a[10]);
	printf("&a[0]:	%x\n",&a[0]);
	printf("&a[1]:	%x\n",&a[1]);
	printf("a:	%x\n",a);
	printf("&a[-1]: %x\n",&a[-1]);

	printf("a[0]:%d,a[-1]:%d\n",a[0],a[-1]);	

	return 0;
}
