#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main() {	
	int f = open("a.txt", O_CREAT | O_RDWR | O_APPEND);	
	if (f == -1) {
		printf("open file failed\n");
		perror("open");
		return -1;
	}
	auto ret = write(f, "parent", 6);
	if (ret == -1) {
		printf("write:%d\n", ret);
                perror("write");
		return -1;
	}
	auto pid = fork();
	if (pid == -1) {
		printf("fork failed\n");
	} else if (pid == 0) {
		execle("");
		write(f, "child", 5);
		while(true) {
			printf("i'm child\n");
			sleep(1);
		}
		return 0;
	}
	printf("parent byebye\n");
	close(f);
	return 0;
}
