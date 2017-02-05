#include<iostream>
using namespace std;

class Test{
public:
    int a;
    virtual void test(){
    }
};

class Test1 : public Test {
public:
    int b;
};


int main() {
    Test obj;
    int *p;
    printf("%ld\n", sizeof(p));
    printf("%ld\n", sizeof(obj));
    printf("%p\n", &obj);
    printf("%p\n", &obj.a);

    
    Test1 obj1;
    obj1.b = 22;
    Test *base = &obj1;

    printf("%ld\n", sizeof(obj1));

    int a = *(int*)((char*)base + 12);
    printf("%d", a);
}
