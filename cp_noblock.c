#include <stdio.h>
#include <stdlib.h>		/*	system function 	*/
#include <sys/stat.h>		/*	fstat function  	*/
#include <unistd.h>		/*	read and write 		*/
#include <fcntl.h>		/*	O_RDONLY,O_WRONLY,mode	*/
#include <error.h>


#define BUFFSIZE 4096







void
set_fl(int fd,int flags)
{
	int val;
	if( (val =  fcntl(fd,F_GETFL,0)  )<0)
		printf("fcntl F_GETFL error");
	
	val |= flags;
	
	if(fcntl(fd,F_SETFL,val)<0)
		printf("fcntl F_SETFL error");
		
}


int 
main(int argc,char * argv[])
{
	char * srcFile;
	char * dstFile;
	struct stat attr;
	char buf[BUFFSIZE];
	int fd,newfd,writeSize,readSize;
	char  cmd[1024000];	/* here can not use char * cmd;	*/
//	char * cmd;

	if(argc==3){
		srcFile = argv[1];
		dstFile = argv[2];
	}else{
		printf("putin too argments!\n");
		return 1;
	}
	
	fd = open(srcFile,O_RDONLY);
	
//	set_fl(fd,O_NONBLOCK);
	fstat(fd, &attr);
	
	newfd = creat(dstFile,attr.st_mode);
	set_fl(newfd,O_NONBLOCK);

//	while(readSize = read(fd,buf,BUFFSIZE))
	for(;;)
	{
		readSize = read(fd,buf,attr.st_size);
		writeSize = write(newfd,buf,readSize);
		if(readSize==-1) {
                        printf("loop break,and readSize is %d\n",readSize);
                        break;
                }
		printf("size of file :%d\n,read buff content:%s\n,readSize is %d\n",attr.st_size,buf,readSize);
//		writeSize = write(newfd,buf,readSize);
		/*
		if(readSize==-1) {
                        printf("loop break\n");
                        break;
                }
		*/
	}

	close(fd);
	close(newfd);
	puts("print the copied file msg:");
	sprintf(cmd,"ls -ls %s",dstFile);
	system(cmd);
	return 0;
}

