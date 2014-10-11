#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	char *message;
	int n;
	pid = fork();
	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}
	if (pid == 0) {
		message = "This is the child\n";
		n = 6;
	} else {
		message = "This is the parent pppppppppp\n";
		n = 3;
	}
	for(; n > 0; n--) {
		printf(message);
		printf("n = %d========\n\n",n);
		sleep(1);
	}
	return 0;
}
