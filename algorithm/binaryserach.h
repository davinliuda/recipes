#include <iostream>
using namespace std;

template<class Type>
bool BinarySerach(Type data[],int len,const Type& value)
{
	Type tmpValue;
	int iBegin = 0,iEnd = len - 1;
	while(iBegin <= iEnd)
	{
		int iMiddle = (iBegin + iEnd) / 2;
		if (value > data[iMiddle])
		{
			iBegin = iMiddle + 1;
		}
		else if (value < data[iMiddle])
		{
			iEnd = iMiddle - 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}


void testBinarySerach()
{
    int srcData[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"found 1:"<<BinarySerach<int>(srcData,10,1)<<endl;
    cout<<"found 10:"<<BinarySerach<int>(srcData,10,10)<<endl;
    cout<<"found 80:"<<BinarySerach<int>(srcData,10,80)<<endl;
}


int main(){
    testBinarySerach();

}


