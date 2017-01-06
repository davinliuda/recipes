#include<memory>
using namespace std;
#include<iostream>
class Test;

void print(std::shared_ptr<Test> obj);

class Test : public std::enable_shared_from_this<Test>{


public:

    typedef std::function<void(std::shared_ptr<Test>)> Fuctor;

    Test(){
        fuctor = std::bind(print, std::placeholders::_1);
    }

    void hello_world(){
        std::cout<<"hello world"<<endl;
    }

    void p(){
        fuctor(shared_from_this());
    }

private:
    Fuctor fuctor;
};


void print(std::shared_ptr<Test> obj) {
    obj->hello_world();
}


int main(){

    auto test = std::make_shared<Test>();
    test->p();
}
