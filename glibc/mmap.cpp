#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

void write_file(){
    int fd;
    fd = open("ttt", O_CREAT|O_RDWR|O_APPEND, 00777);
    for(int i=0;i<1024*1024*1024;){
        if(i + strlen("aaaaaaaaaaaaaaaaa") > 1024*1024*1024){
            break;
        }
        write(fd, "aaaaaaaaaaaaaaaaa", strlen("aaaaaaaaaaaaaaaaa"));
        i = i + strlen("aaaaaaaaaaaaaaaaa");
    }
    close(fd);
}

void write_file1(){
    FILE *f = NULL;
    f = fopen("cc","wa+");
    if(!f){
        perror("open");
        return;
    }
    for(int i=0;i<1024*1024*1024;){
        if(i + strlen("aaaaaaaaaaaaaaaaa") > 1024*1024*1024){
            break;
        }
        fputs("aaaaaaaaaaaaaaaaa", f);
        i = i + strlen("aaaaaaaaaaaaaaaaa");
    }
    fclose(f);
}


std::vector<std::pair<int,void*>> mapfile;


int test_mmap(const char* filedata){
    int fd;
    char*start;
    struct stat sb;
    fd = open(filedata, O_CREAT|O_RDWR|O_APPEND, 00777);

    ftruncate(fd,1024*1024*1024);

    start = (char*)mmap(NULL, 1024*1024*1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(start == MAP_FAILED){
        printf("aaaaaaaaaaaa");
        return -1;
    }

    mapfile.push_back(std::pair<int,void*>(fd, start));
    for(int i=0;i<1024*1024*1024;){
        if(i + strlen("aaaaaaaaaaaaaaaaa") > 1024*1024*1024){
            break;
        }
        strcpy(start + i, "aaaaaaaaaaaaaaaaa");
        i = i + strlen("aaaaaaaaaaaaaaaaa");
    }

    char buf[256];
    for(int i=0;i<1024*1024*1024;){
        if(i + 256 > 1024*1024*1024){
            break;
        }
        memcpy(buf,start + i,256);
        i = i + 256;
    }

    //munmap(start, 1024*1024*1024); /* 解除映射 */
    //close(fd);
}


int main(){
    
    for(int i=0;i<10;i++){
        std::string str = "mmap"+ std::to_string(i);
        test_mmap(str.c_str());
    }
    printf("clean..");
    sleep(100);
}
