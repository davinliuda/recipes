#include <functional>

#include<iostream>

using namespace std;

int test(int a,int b){
	cout<<a<<b<<endl;
	return 1;
}

class Test{
	public:
		int test(int a,int b){
			cout<<a<<b<<endl;

		}
		Test(int a){
			c = a;
		}
		int operator() (int a, int b)
		{
			return a / b / c;
		}
	private:
		int c;

};



/*
 * 解释
 * 一个函数对象的容器类型
 * 可以指向一个函数
 * 一个lambda函数
 * 一个bind的返回
 * 一个重载了operator()的类
 */

typedef std::function<int(int,int)> FUNC_1;




void testFunction1(){
	FUNC_1 f1 = test;
	cout<<f1(1,1)<<endl;


	FUNC_1 f2 = Test(12);

	cout<<f2(1,1)<<endl;
}


typedef std::function<int(Test&,int,int)> FUNC_2;



void testFunction2(){
	
	FUNC_2 f2 = &Test::test;

	Test obj(12);

	f2(obj,1,2);

}

int main(){

	//testFunction1();
	//testFunction2();


    FUNC_1 t;
    t = NULL;
}
