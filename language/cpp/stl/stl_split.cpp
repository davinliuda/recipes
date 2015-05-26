#include <stdlib.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;



vector<string> splitEx(const string& src, string separate_character)
{
	vector<string> strs;

	int separate_characterLen = separate_character.size();
	int lastPosition = 0,index = -1;
	while (-1 != (index = src.find(separate_character,lastPosition)))
	{
		if(index != 0){
			cout<<src.substr(lastPosition,index - lastPosition)<<endl;
			strs.push_back(src.substr(lastPosition,index - lastPosition));
		}
		lastPosition = index + separate_characterLen;
		cout<<"replace"<<endl;
	}
	string lastString = src.substr(lastPosition);
	if (!lastString.empty()){
		strs.push_back(lastString);
		cout<<lastString<<endl;
	}
	return strs;
}



int main(){


	std::vector<std::string> result;

	string s = "aaaaaaaaaa{ADS_JSON}";
	string s = "{ADS_JSON}aaaaaaaaaaa";
	string s = "{ADS_JSON}aaaaaaaaaaa{ADS_JSON}";
	string s = "aaaaaaaaaaa";
	string delim = "{ADS_JSON}";

	
	splitEx(s,delim);

	cout<<result.size()<<endl;


	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}
