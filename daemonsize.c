#include <fcntl.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

#ifndef MAXLINE
	#define MAXLINE 80
#endif

#define SERV_PORT 8000

#define COPYINCR 1024*1024*1024
#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

int
copy(char *src,char *dst)
{
	int fdin, fdout;
	size_t copysz;
	struct stat sbuf;
	off_t fsz = 0;
	
	if ((fdin = open(src, O_RDONLY)) < 0){
		syslog(LOG_ERR,"can’t open %s for readinrg",src);
	}

        if (fstat(fdin, &sbuf) < 0){ /* need size of input file */
                syslog(LOG_ERR,"fstat error");
        }

	if ((fdout = open(dst, O_RDWR | O_CREAT | O_TRUNC,sbuf.st_mode)) < 0){
		syslog(LOG_ERR,"can’t creat %s for writing",dst);
	}

	if (fstat(fdin, &sbuf) < 0){ /* need size of input file */
		syslog(LOG_ERR,"fstat error");
	}

	if (ftruncate(fdout, sbuf.st_size) < 0){ /* set output file size */
		syslog(LOG_ERR,"ftruncate error");
	}

	while (fsz < sbuf.st_size) {
		if ((sbuf.st_size - fsz) > COPYINCR){
			copysz = COPYINCR;
		}else{
			copysz = sbuf.st_size - fsz;
		}

		if ((src = mmap(0, copysz, PROT_READ, MAP_SHARED,fdin, fsz)) == MAP_FAILED){
			syslog(LOG_ERR,"mmap error for input");
		}
		
		if ((dst = mmap(0, copysz, PROT_READ | PROT_WRITE,MAP_SHARED, fdout, fsz)) == MAP_FAILED){
		syslog(LOG_ERR,"mmap error for output");
		}

		memcpy(dst, src, copysz); /* does the file copy */
		munmap(src, copysz);
		munmap(dst, copysz);
		fsz += copysz;
	}
}

int
lockfile(int fd)
{
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_start = 0;
	fl.l_whence = SEEK_SET;
	fl.l_len = 0;
	return(fcntl(fd, F_SETLK, &fl));
}

int
already_running(void)
{
	int fd;
	char buf[16];
	fd = open(LOCKFILE, O_RDWR|O_CREAT, LOCKMODE);
	if (fd < 0) {
		syslog(LOG_ERR, "can’t open %s: %s", LOCKFILE, strerror(errno));
	exit(1);
	}
	if (lockfile(fd) < 0) {
		if (errno == EACCES || errno == EAGAIN) {
			close(fd);
			return(1);
		}
		syslog(LOG_ERR, "can’t lock %s: %s", LOCKFILE, strerror(errno));
		exit(1);
	}
	ftruncate(fd, 0);
	sprintf(buf, "%ld", (long)getpid());
	write(fd, buf, strlen(buf)+1);
	return(0);
}

void 
daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;
	/*
	 * * Clear file creation mask.
	 * */
	umask(0);
	/*
	 * * Get maximum number of file descriptors.
	 * */
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
		printf("%s: can’t get file limit", cmd);
	/*
	 * * Become a session leader to lose controlling TTY.
	 * */
	if ((pid = fork()) < 0)
		printf("%s: can’t fork", cmd);
	else if (pid != 0) /* parent */
		exit(0);
//printf("setsid start\n");
	setsid();
	/*
	 * * Ensure future opens won’t allocate controlling TTYs.
	 * */
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGHUP, &sa, NULL) < 0)
	printf("%s: can’t ignore SIGHUP", cmd);

	if ((pid = fork()) < 0)
		printf("%s: can’t fork", cmd);
	else if (pid != 0) /* parent */
		exit(0);
	/*
	 * * Change the current working directory to the root so
	 * * we won’t prevent file systems from being unmounted.
	 * */
	if (chdir("/") < 0)
		printf("%s: can’t change directory to /", cmd);
	/*
	 * * Close all open file descriptors.
	 * */
	if (rl.rlim_max == RLIM_INFINITY)
	rl.rlim_max = 1024;
	
//printf("pid is:%d\n",getpid() );	

	for (i = 0; i < rl.rlim_max; i++)
		close(i);
	/*
	 * * Attach file descriptors 0, 1, and 2 to /dev/null.
	 * */
	fd0 = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	/*
	 * * Initialize the log file.
	 * */
	openlog(cmd, LOG_CONS, LOG_DAEMON);
	
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
		fd0, fd1, fd2);
		exit(1);
	}else{
	syslog(LOG_ERR,"hell,haision111,this is a damonize process!");
	//exit(2);
	}
}

/*define tcp socket*/
int tcp_server(void)
{
        struct sockaddr_in servaddr, cliaddr;
        socklen_t cliaddr_len;
        int listenfd, connfd;
        char buf[MAXLINE];
        char str[INET_ADDRSTRLEN];
        int i,j,n,sock,new;
	fd_set active_fd_set, read_fd_set;


        listenfd = socket(AF_INET, SOCK_STREAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(SERV_PORT);

        bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

        listen(listenfd, 20);

        printf("Accepting connections ...\n");

	FD_ZERO(&active_fd_set);
	FD_SET(listenfd, &active_fd_set);

        while (1) {
		
		read_fd_set = active_fd_set;
		if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0){
			perror ("select");
			exit (EXIT_FAILURE);
		}
		
		for (i = 0; i < FD_SETSIZE; ++i)
			if (FD_ISSET (i, &read_fd_set)){
				if (i == sock){

		                cliaddr_len = sizeof(cliaddr);
		                connfd = accept(listenfd,(struct sockaddr *)&cliaddr, &cliaddr_len);
					if(connfd<0){
						syslog(LOG_ERR,"accept failed!\n");
						FD_SET (new, &active_fd_set);
					}else{
						n = recv(connfd, buf, MAXLINE,MSG_OOB);
						printf("received from %s at PORT %d\n",
						        inet_ntop(AF_INET, &cliaddr.sin_addr,str,sizeof(str)),
						        ntohs(cliaddr.sin_port));
						
						for (i = 0; i < n; i++){
						        buf[i] = toupper(buf[i]);
							send(connfd, buf, n,MSG_OOB);
							close(connfd);
						}
					}
				}
			}
	}
}


int
main(int argc,char * argv[]){
	int err;
	pthread_t tid;
	char *cmd;
	struct sigaction sa;
	if ((cmd = strrchr(argv[0],'/')) == NULL){
		cmd = argv[0];
	}else{
		cmd++;
	}

	daemonize(cmd);

	if (already_running()) {
                syslog(LOG_ERR, "daemon already running");
                exit(1);
        }

	tcp_server();
}
