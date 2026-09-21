#include<iostream>
using namespace std;

class Node{
	public:
		Node*next;
		int val;
		Node(int v){
			val = v;
			next = NULL;
		}
};
class SinglyLL{
	public:
	Node*head;
	Node*tail;
	
	SinglyLL(){
		head = tail = NULL;
	}
	
	void insertAThead(int val){
		Node *newNode = new Node(val);
		if(head == NULL){
			head = tail = newNode;
		}else{
			newNode->next = head;
			head =  newNode;
		}
	}
	void insertATtail(int val){
		Node *newNode = new Node(val);
		if(head == NULL){
			head = tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
	void insert_After(int val,int pos){
		if(pos<0){
			cout<<"Invalid Position"<<endl;
			return;
		}
		
		Node *newNode =  new Node(val);
		if(head == NULL){
			head = tail = newNode;
		}else{
			Node *temp = head;
			for(int i=0;i<pos-1;i++){
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		
	}
	bool Search(int key){
		if(head == NULL){
			cout<<"LinkedList is Empty\n";
			return false;
		}
		Node *temp = head;
		while(temp!=NULL){
			if(temp->val == key){
				return true;
			}
			temp = temp->next;
		}
		return false;
		
	}
	void reverse(){
		Node* prev = NULL;
		Node *curr = head;
		Node * newNode = NULL;
		while(curr != NULL){
			newNode = curr->next;
			curr->next = prev;
			prev =  curr;
			curr = newNode;
		}
		head = prev;
	}
	
	void display(){
		Node *temp = head;
		while(temp!=NULL){
			cout<<temp->val<<"->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
};
int main(){
	SinglyLL sl;
	sl.insertAThead(12);
	sl.insertAThead(9);
	sl.insertATtail(98);
	sl.insertATtail(45);
	sl.insert_After(12,3);
	sl.print();
	sl.insert_After(12,-1);
	sl.print();
	int key;
	cout<<"Enter Key: ";
	cin>>key;
	if(sl.Search(key)){
		cout<<"Found\n";
		
	}else{
		cout<<"Not Found\n";
		
	}

	sl.reverse();
	sl.print();
	
	
	
	
}
