#include<iostream>
using namespace std;
#include <vector>
#include <list>

//选择排序，就是在后面不断的选最小的，把最小的那个数字交换到最前面
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

//插入排序是，先保持前面的序列是有序的，然后把后面的数据插入到有序里面
//解题思路是，需要在有序里面寻找，然后移动并插入到里面
int insert_sort(std::vector<int>& data) {
    for(int i = 0; i < data.size(); i++){
        int j = i-1;
        int key = data[i];
        for(; j >= 0; j--) {
            if(data[j] > key){
                data[j+1] = data[j];
            }else{
                break;
            }
        }
        data[j+1] = key;
    }
}

//冒泡排序，就是把最大的不断的向后面移动
int bubble_sort(std::vector<int>& data) {
    for(int i = 0; i < data.size(); i++) {
        for ( int j = i + 1; j < data.size(); j++){
            if(data[i] > data[j]){
                std::swap(data[i], data[j]);
            }
        }
    }
}


int bubble_sort(std::list<int>& data) {
    for(auto it = data.begin(); it != data.end(); ++it){
        auto it1 = it;
        std::advance(it1, 1);
        for(;it1 != data.end(); ++it1){
            if(*it1 < *it){
                std::swap(*it, *it1);
            }
        }
    } 
}

//快速排序
//先找第一个数字
//然后从右向左找，直到找到一个比它大的数字
//然后和右边的交换
//然后从左向右找，直到找到一个比它小的数字
//然后和左边交换
//反复上面几个步骤，找到第一个数字的位置，放置其中。然后用分治反复做。

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
        
        quick_sort(data, begin, i - 1);
        quick_sort(data, i + 1, end);
    }
}



void max_heap_sort(std::vector<int>& data) {
        
}

template<class T>
void print(typename T::iterator begin, typename T::iterator end){
    for(; begin != end; ++begin){
        std::cout<<*begin<<" ";
    }
    std::cout<<std::endl;
}


int main(){
    
    {
        std::list<int> data= {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
        bubble_sort(data);  
        print<std::list<int>>(data.begin(), data.end());
    }

    { 
        std::vector<int> data = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
        select_sort(data);
        print<std::vector<int>>(data.begin(), data.end());
    }

    {
        std::vector<int> data = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
        bubble_sort(data);
        print<std::vector<int>>(data.begin(), data.end());
    }
    {
        std::vector<int> data = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
        quick_sort(data, 0, data.size() - 1);
        print<std::vector<int>>(data.begin(), data.end());
    }
    {
        std::vector<int> data = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
        insert_sort(data);
        print<std::vector<int>>(data.begin(), data.end()); 
    }
    
}      
