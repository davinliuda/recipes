#include<iostream>
#include<vector>
using namespace std;

class Cat{
public:
    Cat(){
        cout<<"constructor function"<<endl;
    }
    ~Cat(){
        cout<<"destructor function"<<endl;
    }
    Cat(const Cat& c){
        cout<<"copy constructor function"<<endl;
    }
    Cat& operator=(const Cat& c){
        cout<<"assign constructor function"<<endl;
    }
    Cat(Cat&& c){
        cout<<"move assgin function"<<endl;
    }

};

int main() {
    std::vector<Cat> vec_obj;
    //vec_obj.resize(6);
    //vec_obj[0] = Cat{};
    //vec_obj[1] = Cat{};
   

    for(int i=0;i<10;i++){
        vec_obj.push_back(Cat{});
        std::cout<<vec_obj.capacity()<<endl;
    }
  
    std::cout<<"================="<<endl; 
    vec_obj.resize(20);
    cout<<vec_obj.size()<<endl;
 
    //vec_obj.push_back(Cat{});
    //vec_obj.erase(vec_obj.begin());
   
    //vec_obj.push_back(Cat{});
    //std::cout<<vec_obj.capacity()<<endl; 
}

