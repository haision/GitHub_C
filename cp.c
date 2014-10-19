#include <stdio.h>
#include <stdlib.h>		/*	system function 	*/
#include <sys/stat.h>		/*	fstat function  	*/
#include <unistd.h>		/*	read and write 		*/
#include <fcntl.h>		/*	O_RDONLY,O_WRONLY,mode	*/
#define BUFFSIZE 4096

int main(int argc,char * argv[])
{
	char * srcFile;
	char * dstFile;
	struct stat attr;
	char buf[BUFFSIZE];
	char  cmd[1024];	/* here can not use char * cmd;	*/

	if(argc==3){
		srcFile = argv[1];
		dstFile = argv[2];
	}else{
		printf("putin too argments!\n");
		return 1;
	}
	int fd,newfd,writeSize,readSize;
	fd = open(srcFile,O_RDONLY);
	fstat(fd, &attr);
	
	newfd = creat(dstFile,attr.st_mode);
	
	while(readSize = read(fd,buf,BUFFSIZE))
	{
		if(readSize==-1) {
                        printf("loop break\n");
                        break;
                }
//		printf("size of file :%d\n,read buff content:%s\n,readSize is %d\n",attr.st_size,buf,readSize);
		writeSize = write(newfd,buf,readSize);
		/*
		if(readSize==-1) {
                        printf("loop break\n");
                        break;
                }
		*/
	}

	close(fd);
	close(newfd);
	puts("print the cpied file msg:");
	sprintf(cmd,"ls -ls %s",dstFile);
	system(cmd);
	return 0;
}

