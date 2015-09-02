#include<memory>
#include<iostream>
using namespace std;



class Test{
public:
    int a;
};

int main(){
    shared_ptr<Test> obj = make_shared<Test>();

    weak_ptr<Test> d = obj;

    
    shared_ptr<Test> cc = d.lock();
}
