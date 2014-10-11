#include <stdio.h>
#include <string.h>

int main (void)
{
	char src[]="thy431======12";
	char dst[22];
	printf("src address is: %x\n",src);
	printf("dst address is: %x\n",dst);
	//*abc=1;
	strncpy(dst,src,strlen(src));
	//puts(abc);

	printf("dst len: %d\n",strlen(dst));	

	printf("src len: %d\n",strlen(src));
	printf("src is: %s\n",src);
	
	printf("dst is: %s\n",dst);	
	printf("dst len: %d\n",strlen(dst));
	return 0;
}
