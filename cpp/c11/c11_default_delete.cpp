#include<iostream>
using namespace std;


class Test{
public:
    Test() = default;

    Test(int b){
        cout<<b<<endl;
    }
    void* operator new(size_t size) = delete;

};


int main(){
    Test obj;//default


    Test* a = new Test();

}

