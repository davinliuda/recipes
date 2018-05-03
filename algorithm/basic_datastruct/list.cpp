#include <iostream>
using namespace std;


struct Node {
	int val;
	Node* next;
	Node(): next(NULL), val(0) {
	}
};


Node* make_list() {
	Node *head = NULL;
	Node *pre = NULL;
	for(int i = 0; i < 10; i++){
		Node* node = new Node();
		node->val = i;
		if ( head == NULL ) {
			head = node;
			pre = head;
		} else {
			pre->next = node;
			pre = node;
		}
	}
	return head;
}


void print_list(Node* node) {

	for (; node != NULL; node = node->next) {
		std::cout << node->val << " ";
	}
	std::cout<<std::endl;
}


void custom_reverse(Node*& node) {
	if (node == NULL) {
		std::cout<<"aa";
		return;
	} else if(node->next == NULL) {
		std::cout<<"bb";
		return;
	}

	Node* pre = node;
	node = node->next;
	pre->next = NULL;
	while (node) {
		Node* cur = node;
		node = node->next;
		cur->next = pre;	
		pre = cur;
	}
	node = pre;
}


Node* merge(Node* node, Node* node) {
	
}

Node* backwardN(Node* node) {
	
}

int main() {
	Node* node = make_list();	
	print_list(node);
	custom_reverse(node);
	print_list(node);
}
