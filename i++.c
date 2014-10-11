#include <stdio.h>

int f1(int i){
	i++;
	return i;
}


int f2(int j){
	++j;
	return j;
}

int main(void){
	printf("f1(3)===%d\n",f1(3));
	printf("f2(3)===%d\n",f2(3));
	

	int a=0;
	a = (++a)+(++a)+(++a)+(++a);
	printf("a= %d\n",a);

	return 0;
}
