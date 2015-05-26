#ifndef _SAMPLEPLUGIN_H
#define _SAMPLEPLUGIN_H
#include"plugin.h"
#include<iostream>
using namespace std;
class SamplePlugin : public Plugin 
{
public:
	void Print()
	{
		cout<<"i'm in export"<<endl;
	}
};




#endif
