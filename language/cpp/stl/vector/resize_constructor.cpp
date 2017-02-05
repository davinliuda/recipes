#include <iostream>
using namespace std;
#include <vector>

class A{
public:
    A(){
        std::cout<<"constructor"<<std::endl;
    }

    ~A(){
        std::cout<<"destructor"<<std::endl;
    }
    
    const A& operator= (const A& a){
        std::cout<<"operator="<<std::endl;
        return *this;
    }

    A(const A& a){
        std::cout<<"copy_constructor"<<std::endl;
    }
};


int main(){

    std::vector<A> obj;
    obj.resize(4);
    
    std::cout<<obj.capacity();    

    obj[0] = A();

    //obj.push_back(A());
    std::cout<<obj.capacity();
}
