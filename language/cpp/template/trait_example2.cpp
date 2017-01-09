#include<iostream>
using namespace std;

struct cat_tag{
    int a;
}; //这只是个空类，目的是激发函数重载，后面会解释
struct dog_tag{

    int c;
}; //同上


class Dog
{
public:
    int b;
    typedef  dog_tag  type;
};


class Cat
{
public:
    typedef cat_tag type;
};



//inner class

template<class T>
void Accept(T dog, dog_tag obj)
{
    std::cout<<dog.b<<endl;
    std::cout<<obj.c<<endl;
    //std::cout<<dog_tag<<endl; 
}
 
template<class T>
void Accpet(T cat, cat_tag) // 同上
{
    
}


template<class T> // T表示接受的是何种动物
void AcceptAnimals(T animal)
{
    Accept(animal, typename T::type()); 
};

int main(){
    Dog obj;
    AcceptAnimals<Dog>(obj);
}
