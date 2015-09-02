#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


int get_file_list(const std::string& file,std::vector<std::string>& lst){
    DIR *dirptr = opendir(file.c_str());
    if(dirptr == NULL){
        return -1;
    }
    struct dirent *entry;
    while( (entry = readdir(dirptr)) !=NULL ){
        cout<<"a"<<endl;
        if((strcmp(entry->d_name,".")==0)||(strcmp(entry->d_name,"..")==0)){
            continue;
        }
        printf("%d\n",entry->d_type);
        //if (entry->d_type == DT_DIR || entry->d_type == DT_REG){
        //    lst.push_back(entry->d_name);
        //}
    }
    closedir(dirptr);
    return 0;
}

int main()
{

    std::vector<std::string> result;
    cout<<get_file_list("/tmp/liuda/wifidata/have_pwd/20150604/",result)<<endl;
    for(size_t i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}
