#ifndef BINARY_SERACH_H
#define BINARY_SERACH_H


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

#endif

