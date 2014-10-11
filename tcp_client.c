#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 2000
#define SERV_PORT 8000
#define CLI_PORT 10000

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr,cliaddr;
	char buf[MAXLINE];
	int sockfd, n,savefd;
	char *str;
 	char *result;
	   
	if (argc != 2) {
		fputs("usage: ./client message\n", stderr);
		exit(1);
	}
	str = argv[1];
    
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "218.244.140.198", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

//        cliaddr.sin_family = AF_INET;
//        inet_pton(AF_INET, "192.168.1.191", &cliaddr.sin_addr);
//        cliaddr.sin_port = htons(CLI_PORT);
//
//    	bind(sockfd,(struct sockaddr *)&cliaddr,sizeof(cliaddr));

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	write(sockfd, str, strlen(str));
	n = read(sockfd, buf, 2000);
	printf("Response from server:\n");
	printf("%s\d",buf);
	close(sockfd);
	return 0;
}
