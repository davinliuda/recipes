#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(){
	int fd = -1 ;
	void* addr = NULL;
	char buf[4096] = "liuda nihao";
	fd = shm_open("hello", O_RDWR|O_CREAT, 00777);
	if (fd == -1){
		return -1;
	}
	
	ftruncate(fd, 4096*4096);
	
	addr = mmap(NULL, 4096*4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, SEEK_SET);
	
	do{
		for(int i=0;i<4096*4096/strlen(buf);i++){
			memcpy((char*)addr + i*strlen(buf), buf, strlen(buf));
		}
		
	
	}while(false);
	
	munmap(addr, 4096*4096);
	shm_unlink("hello");		
}
