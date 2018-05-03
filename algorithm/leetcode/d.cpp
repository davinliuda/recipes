#include <iostream>  
#include <time.h>  
#include <stack>  
#include <stdlib.h>
using namespace std;  

void shuffle(int a[], int n)  
{  
	srand(time(NULL));  
	for(int i = 0; i < n; i++)  
	{  
		int index = rand() % n;  
		int tmp = a[i];  
		a[i] = a[index];  
		a[index] = tmp;  
	}  
}  

void f(int a[], int n)  
{  
	stack<int> s;  
	if(n <= 1)  
		return;  

	s.push(a[0]);  
	for(int i = 1; i < n; i++)  
	{  
		while(!s.empty() && a[i] > s.top())  
		{  
			cout<<s.top()<<','<<a[i]<<endl;  
			s.pop();  
		}  

		s.push(a[i]);  
	}  
}  

int main(int argc, char *argv[])  
{  
	int *a = new int[atoi(argv[1])];  
	for(int i = 0; i < atoi(argv[1]); i++)  
	{  
		a[i] = i + 1;  
	}  
	shuffle(a, atoi(argv[1]));  
	for(int i = 0; i < atoi(argv[1]); i++)  
	{  
		cout<<a[i]<<' ';  
	}  
	cout<<endl;  
	cout<<"------------------------------"<<endl;  

	f(a, atoi(argv[1]));  
	return 0;  
}  
