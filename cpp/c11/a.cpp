#include<iostream>
using namespace std;
#include<vector>

class Test{
public: 
    typedef vector<int>::iterator            iterator;    
    iterator begin(){return a.begin();}
private:
    vector<int> a;
};

int main(){

    Test o;

    Test::iterator it = o.begin();


}
