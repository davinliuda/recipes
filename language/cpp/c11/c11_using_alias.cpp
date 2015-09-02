#include<iostream>
#include <functional>
using namespace std;



//定义模板别名
template <typename T> using action = std::function<void(int,int,T&)>;

int main(){
    int x = 1;
    action<int> b = [](int,int,int&){ cout<<"a";return 0;};
}
