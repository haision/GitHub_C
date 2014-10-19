#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[] = "1234567890";
	memmove(buf + 1, buf, 3);
	printf("first buf:%s\n",buf);
	//memset(buf,0,4);
	printf("second buf:%s\n",buf);
	return 0;
}
