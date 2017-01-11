#include <iostream>
using namespace std;

int sum(int* src,int n){
	if(n == 0){
		return 0;
	}
	int a = Sum(src,n-1);
	return n + a;
}


void testSum()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<Sum(a,10)<<endl;
}

int main(){
    testSum();
}
