#include<iostream>
using namespace std;
#include<vector>

//类模板全特化

template<class T1, class T2>
class Test{
public:
    void print(T1 a, T2 b) {
        
    }

};


//类模板全特化
template<>
class Test<int, int>{
public:
    void print(int a, int b) {
        std::cout<<a<<" "<<b<<std::endl;
    }

};


//类模板偏特化

template<class T2>
class Test<int, T2> {
public:
    void print(int a, T2 b) {
        std::cout<<a<<"  "<<b<<std::endl;
    }
};


//类模板特化为指针
template<class T1, class T2>
class Test<T1*, T2*> {
public:
    void print(T1 a , T2 b) {
       std::cout<<"FFFFFFF"<<endl;
    }
};


//特化为另外一个模板


template<class T1, class T2>
class Test<std::vector<T1>, std::vector<T2> >{
public:
    void print(const std::vector<T1>& a, const std::vector<T2>& b){
        
    }

};

int main(){
    Test<int, int> obj;
    obj.print(1, 2);

    Test<int, std::string> obj1;
    obj1.print(1, "xxxxxxx");

    Test<int*, int*> obj2;
    obj2.print(3, 3);

    {
        std::vector<int> a;
        a.push_back(1);
        a.push_back(2);

        std::vector<int> b;
        b.push_back(1);
        b.push_back(2);

        Test<std::vector<int>, std::vector<int> > obj3;
        obj3.print(a, b);
    }

}



