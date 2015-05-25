#include <string.h>
#include<iostream>
#include<stdint.h>
using namespace std;

template <size_t NBITS>
struct NbitsIntegerTraits
{
};

template <>
struct NbitsIntegerTraits<8>
{
    typedef uint8_t data_type;
};

template <>
struct NbitsIntegerTraits<16>
{
    typedef uint16_t data_type;
};



class ByteBuffer{
public:
    ByteBuffer(){
        strcpy(buf,"1111");
    }    

    template<size_t NBITS>
    typename NbitsIntegerTraits<NBITS>::data_type get_int(){
        typename NbitsIntegerTraits<NBITS>::data_type value = get<typename NbitsIntegerTraits<NBITS>::data_type>();
        return value;
    }

private:
    template<typename T>
    inline T get(){
        return *(T*)buf;   
        
    }
    char buf[16];
};


class ByteBufferEx{
public:
    ByteBufferEx(){
        strcpy(buf,"1111");
    }

    uint8_t  get_int8(){
        return *(uint8_t*)buf; 
    }
    uint16_t get_int16(){
        return *(uint16_t*)buf;
    }

private:
    char buf[16];
};



int main(){

    ByteBuffer obj;
    cout<<obj.get_int<8>()<<endl;
    cout<<obj.get_int<16>()<<endl;


    ByteBufferEx obj1;
    cout<<obj1.get_int8()<<endl;
    cout<<obj1.get_int16()<<endl;

}
