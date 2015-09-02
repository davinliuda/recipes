#include<functional>
#include<iostream>


using namespace std;



class Test{
public:
	void test(int a,int b){
        	
	}
		
	static void callback(int a,int b){
		//function<void(int,int)> f = bind(&Test::test,this,std::placeholders::_1,std::placeholders::_2);
		//f(a,b);
		
			
		cout<<"aaa"<<endl;
	}
};



typedef void (*CallBack)(int,int);



void loop(CallBack f){
	f(1,2);
}




int main(){
	
	loop(&Test::callback);


	
}



