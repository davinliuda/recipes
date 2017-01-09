#include <iostream>
using namespace std;

void print()
{
  cout << "empty" << endl;  
}

template <typename T, typename... Args>
void print(T head, Args... args)
{
    cout << head << ",";
    print(args...);      
}

int main()
{
    print(1, 2, 3, 4);
    return 0;    
}
