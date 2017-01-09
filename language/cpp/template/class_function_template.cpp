#include<iostream>
#include <functional>
using namespace std;



class Test{
public:
    template<typename T>
    void get(const T& obj){
        obj();
    }

};



template <typename T> using action = std::function<int(int,int,T&)>;

int main(){

    Test obj;
    obj.get([](){cout<<"e"<<endl;});
}
