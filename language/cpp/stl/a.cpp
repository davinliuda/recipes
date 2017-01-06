#include<iostream>
using namespace std;
#include<vector>

class AA
{
public:
    AA(const AA& aa)
    {
        a = aa.a;
        c = new int(*aa.c);
        cout<<"aaa"<<endl; 
    }
    
    AA(int b) :a(b){ c=new int(2); }
    ~AA()
    {
        delete c;
    }
    int a;
    int *c;

};

int main(int argc, char* argv[])
{
    AA a(1);
    AA b(2);
    std::vector<AA> v;
    v.push_back(a);
    v.push_back(b);
    auto itt = v.begin();
    //v.erase(++itt);//OK
    //  v.erase(itt);//segment dump
    //      return 0;
    //     
    //
}
