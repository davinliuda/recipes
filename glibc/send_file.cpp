#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include<iostream>
using namespace std;

int main(int argc,char** argv){


	char* filename = argv[1];

	int fd = open(filename, O_RDONLY);

	if(fd <0) {
		perror("open");
		return -1;
	}


	struct stat statbuff;  
	stat(filename, &statbuff);
	


	int sd = socket(PF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in sa;
	sa.sin_family = PF_INET;
	sa.sin_port = htons(1033);
	sa.sin_addr.s_addr = inet_addr("0.0.0.0");
	

	if(bind(sd, (struct sockaddr *)&sa,sizeof(sa)) < 0){
		perror("bind");
		exit(errno);
	}


	if(listen(sd,1) < 0){
		perror("listen");
		exit(errno);
	}


	int client;
	if((client = accept(sd, NULL, NULL)) < 0){
		perror("accept");
		exit(errno);
	}



	int fileSize = statbuff.st_size;
	int buffSize = 4*1024;
	int realSize = 0;	

	struct timeval begin;
	gettimeofday(&begin,NULL);



	if(strcmp(argv[2],"sendfile") == 0)
	{
		cout<<"sendfile"<<endl;
		off_t cur = 0;	
		while(true){
			size_t len = sendfile(client,fd,&cur,buffSize);
			if(len <= 0){
				perror("sendfile");
				break;
			}
			if(cur == fileSize){
				printf("over:%d,fileSize:%d",cur,fileSize);
				break;
			}
			if(fileSize - cur < buffSize){
				buffSize = fileSize - cur;
			}
			cur = cur + len;
			realSize = realSize + len;
		}
	}else if(strcmp(argv[2],"file") == 0){

		cout<<"read and write"<<endl;
		realSize = 0;
		char buf[buffSize];

		while(true){

			int rc = read(fd,buf,buffSize);
			if(rc <= 0){
				perror("read");
				break;
			}	
			rc = write(client,buf,rc);
			if(rc <= 0){
				perror("write");
				break;
			}
			realSize = realSize + rc;
		}

	}else{
		cout<<"read"<<endl;
		char* buf = new char[1024*1024*100];
		int blockSize = 1024*4;
		int cur = 0;
		int rc = 0;
		while(true){
			rc = read(fd,buf+cur,blockSize);
			if(rc <= 0){
				perror("read");
				break;
			}
			cur = cur + blockSize;
		}

		
		gettimeofday(&begin,NULL);

		buf[fileSize] = '\0';
		cur = 0;
		realSize = 0;
		while(true){
			rc = write(client,buf + cur,blockSize);
			if(rc <= 0){
				perror("write");
				break;
			}
			cur = cur + rc;
			if(cur >= fileSize){
				break;
			}
			realSize = realSize + rc;
		}


	}



	struct timeval end;
	gettimeofday(&end,NULL);


	printf("costtime:%d,%d,buf:%d",end.tv_sec-begin.tv_sec,end.tv_usec-begin.tv_usec,realSize);


	close(fd);
	close(sd);
	close(client);

}
