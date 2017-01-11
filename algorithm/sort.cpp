#include<iostream>
using namespace std;
#include <vector>


int select_sort(std::vector<int>& data) {
    for(int i = 0; i < data.size(); i++){
        int min = data[i];
        int index = -1;
        for(int j = i+1; j < data.size(); j++){
            if(min > data[j]){
                min = data[j];
                index = j;
            }
        }
        if(index != -1){
            data[index] = data[i];
            data[i] = min;
        }
    }

}


int insert_sort(std::vector<int>& data) {
    

}

int bubble_sort(std::vector<int>& data) {
    for(int i = 0; i < data.size(); i++) {
        for ( int j = i + 1; j < data.size(); j++){
            if(data[i] > data[j]){
                std::swap(data[i], data[j]);
            }
        }
    }
}



void quick_sort(std::vector<int>& data, int begin, int end){
    if(begin < end){
        int i = begin;
        int j = end;
        int tmp = data[begin];
        while(i < j){
            while(i < j && tmp < data[j]) j--;
            if(i < j){
                data[i] = data[j];
                i++;
            }
            
            while(i < j && tmp > data[i]) i++;
            
            if(i < j){
                data[j] = data[i];
                j--;
            }
        }    
        data[j] = tmp;
        std::cout<<j<<endl;
        
        quick_sort(data, begin, i - 1);
        quick_sort(data, i + 1, end);
    }
}



void max_heap_sort(std::vector<int>& data) {
    
}


int main(){
    std::vector<int> data = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
    //select_sort(data);
    //bubble_sort(data);
    quick_sort(data, 0, data.size() - 1);
    for(int i=0;i<data.size(); i++){
        std::cout<<data[i]<<" ";
    }
}      
