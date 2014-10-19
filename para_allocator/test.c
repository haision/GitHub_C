#include<stdio.h>

extern void f(int *);

int b = 2122;

int main(void){
	f(b);
	printf("b value is %d\n",b);
	return 0;
}
void f(int  *i){
	*i = 8883;
}
