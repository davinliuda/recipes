#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
       #include <sys/wait.h>
/**
* File: execl.c
*
*/
int make(){
	int ret;
	pid_t pid;
	int result;
	if( (pid = fork() ) < 0 ){
		printf("fork error\n");
	}
	else if( 0 == pid ){
		ret=(execl("/bin/bash","/bin/bash","/data0/dev/b.sh",0));
		if (ret != -1){
			printf("OK\n");
			printf("%d\n", ret);
		}else{
			printf("failed\n");
			printf("%d\n", ret);
			perror("error:");
		}
	}
	return 0;
    	waitpid(pid,&result,NULL);
}


int main(){

	make();
	printf("hello wolrd");

}
