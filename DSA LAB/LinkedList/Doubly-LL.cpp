#include<iostream>
using namespace std;
class Node{
	public:
		Node*next;
		Node*prev;
		int val;
	Node(int v){
		val =  v;
		next = prev = nullptr;
	}
	
	
};
class DoublyLL{
	public:
		Node*head;
		Node*tail;
		DoublyLL(){
			head = tail = nullptr;
		}
	void push_front(int val){
		Node *newNode = new Node(val);
		if(head == nullptr){
			head = tail = newNode;
		}else{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}	
	}
	void push_back(int val){
		Node *newNode = new Node(val);
		if(head == nullptr){
			head = tail= newNode;
		}else{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		
		
	}
	void insert_mid(int val,int pos){
		Node *newNode = new Node(val);
		if(head == nullptr){
			head = tail= newNode;
		}else{
		
		Node *temp = head;
		for(int i=0;i<pos-1;i++){
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
	}
	}
	void print(){
		Node *temp = head;
		while(temp != nullptr){
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	void print_reverse(){
		Node*temp= tail;
		while(temp!= nullptr){
			cout<<temp->val<<" ";
			temp = temp->prev;
		}
		cout<<endl;
	}
};
int main(){
	DoublyLL dll;
	dll.push_front(10);
	dll.print();
	dll.push_front(12);
	dll.print();
	dll.push_back(19);
	dll.push_back(4);
	dll.print();
	dll.print_reverse();
	dll.insert_mid(34,2);
	dll.print();
	dll.insert_mid(12,2);
	dll.print();
	
}
