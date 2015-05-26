#include<iostream>
using namespace std;
class HashTable{
public:
	HashTable(int bucketCount){
		bucketCount_ = bucketCount;
		base_ = (Item**)malloc(bucketCount_*sizeof(Item*));
		memset(base_,0,bucketCount_*sizeof(Item*));
	}
	~HashTable(){
		if(base_){
			free(base_);
		}
	}
	int Get(int key,int &value){
		int index = key % bucketCount_ ;
		Item* cur = base_[index];
		while(cur){
			if(cur->key == key){
				value = cur->value;
				return 0;
			}
			cur = cur->next;
		}
		return -1;
	}
	int Put(int key,int value){
		int tmp;
		if(!Get(key,tmp)){
			return -1;
		}else{
			int index = key % bucketCount_ ;
			Item* newNode = (Item*)malloc(sizeof(Item));
			newNode->next = base_[index];
			newNode->key = key;
			newNode->value = value;
			base_[index] = newNode;
		}
		return 0;
	}
private:
	struct Item{
		int key;
		int value;
		struct Item* next;	
	};
	Item** base_;
	int bucketCount_;
};

int main(){
	HashTable pHash(10);	
	pHash.Put(12,123);
	int value;
	int ret = pHash.Get(12,value);
	cout<<ret<<" "<<value<<endl;
	getchar();
}
