#include<iostream>
using namespace std;



//for sum(v, v+4)
//
template<typename Iter>
class mytraits {
public:
    typedef typename Iter::value_type value_type;
};


template<typename T>
class mytraits<T*> {
public:         
    typedef T value_type;
};

template<typename Iter>
typename mytraits<Iter>::value_type sum(Iter a, Iter b) {
    typename mytraits<Iter>::value_type sum(0);
    for(Iter i=a; i!=b; ++i) sum += *i;
    return sum;
}


//sum<int, int*>
template<typename T,typename Iter>
T sum(Iter a, Iter b) {
    T sum(0);
    for (Iter i = a; i!=b; ++i) {
        sum = sum + *i;
    }
    return sum;
}

int main() {
    int v[4] = {1,2,3,4};
    cout<<sum<int,int*>(v,v+4);
    

    cout<<sum(v,v+4);
}
