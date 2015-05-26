#include "binaryserach.h"
#include "sum.h"
#include <iostream>
using namespace std;

void testBinarySerach()
{
	int srcData[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<"found 1:"<<BinarySerach<int>(srcData,10,1)<<endl;
	cout<<"found 10:"<<BinarySerach<int>(srcData,10,10)<<endl;
	cout<<"found 80:"<<BinarySerach<int>(srcData,10,80)<<endl;
}

void testSum()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<Sum(a,10)<<endl;
}


//int main()
//{
//	//二分查找.分治法。
//	//testBinarySerach();
//	testSum();
//	int a;
//	cin>>a;
//}