#include <stdio.h>

int main(){
	const char * i = "abcdefghijk";
	char * j = "ABCDEFGHIJK";
	int r = 2;
	while(r--){
	*j++ = *i++;
	}
	printf("i is :%s\n",i);
	printf("j is :%s\n",j);

	return 0;
}
