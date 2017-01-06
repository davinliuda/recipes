#include<vector>
using namespace std;

#include<string>

#include<iostream>

struct Test{
    Test(int a,int b){
        this->a = a;
        this->b = b;
    }
    Test(){
        cout<<"bbb"<<endl;
    }
    Test(const Test& obj){
        cout<<"aaa"<<endl;
    }

    int a;
    int b;
    char* ptr;
};


int main(){


    Test b;
    b.a = 1;
    b.b = 2;
    
    std::vector<Test> obj;
    obj.emplace(obj.begin(),1,2);


    b.a = 23;
    
    cout<<b.a<<endl;
    cout<<obj[0].a<<endl;
    
}
