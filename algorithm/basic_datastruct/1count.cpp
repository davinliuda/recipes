#include<iostream>
using namespace std;

int main(){
    int a;
    a = 1;
    int sum = 0;
    while(a!=0){
        
        if(a % 10 ==1){
            sum = sum + 1;
        }
        a = a / 10;
    }
    std::cout<<sum<<endl;

}
