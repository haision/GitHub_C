#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[] = "1234567890\n";
	memcpy(buf + 1, buf, 10);
	printf(buf);
	return 0;
}
