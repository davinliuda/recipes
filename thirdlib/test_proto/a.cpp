#include "a.pb.h"
#include "b.pb.h"
#include "iostream"
using namespace std;

using namespace ProtoCS;

string BinToHex(const string &strBin, bool bIsUpper = false)  
{  
	string strHex;  
	strHex.resize(strBin.size() * 2);  
	for (size_t i = 0; i < strBin.size(); i++)  
	{  
		uint8_t cTemp = strBin[i];  
		for (size_t j = 0; j < 2; j++)  
		{  
			uint8_t cCur = (cTemp & 0x0f);  
			if (cCur < 10)  
			{  
				cCur += '0';  
			}  
			else  
			{  
				cCur += ((bIsUpper ? 'A' : 'a') - 10);  
			}  
			strHex[2 * i + 1 - j] = cCur;  
			cTemp >>= 4;  
		}  
	}  

	return strHex;  
}  



int main() {
	Msg msg;
	msg.SetExtension(ProtoCS::id, 7);
	ProtoCS::ModReq* modReq = msg.MutableExtension(ProtoCS::mod_req); 
	modReq->set_b(true);

	std::string str;
	bool ret = msg.SerializeToString(&str);
	std::string ss = BinToHex(str);
	std::cout<<ss<<std::endl;
}
