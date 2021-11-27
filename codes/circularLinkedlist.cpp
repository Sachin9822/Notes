#include<iostream>

using namespace std;

class Node {
	public:
	int data;
	Node *next;
};
class Linkedlist{
	int x;
	Node *head;
	public:
	Linkedlist(){
		head = NULL;
		x = 0;
	}
	~Linkedlist(){
	}
	void createlist();
	void insert_node();
	void find_node();
	void display();
	void delete_node();
};

Linkedlist secondlist;

void swap(Node *one,Node *two){
	int temp;
	temp = one->data;
	one->data = two->data;
	two->data = temp;
}

void Linkedlist::delete_node(){
	int pos,x = 0;
	Node *temp;
	Node *temp2,*prevNode;
	temp = head;
	while(temp->next != head){
		x++;
		temp = temp->next;
	}
	cout<<"x : "<<x<<endl;
	cout<<"1: Delete at the begining\n2: Delete at the end\n3: Delete at any position\n";
	int a;
	cin>>a;
	if(a == 1){
		prevNode = head;
		head = head->next;
		delete prevNode;
	}
	else{
		if(a == 2){
			temp = head;
			for(int i = 1 ; i<x-1;i++){
				temp = temp->next;
			}
			temp2 = temp->next;
			temp->next = head;
			delete temp2;
		}
		else if(a == 3){
			cout<<"Enter the position to delete node: ";
			cin>>pos;
			if(pos>0&&pos<=x){
				x = 0;
			}
			else{
				cout<<"Invalid position\n";
				return;
			}
			temp = head;
			for(int i = 1 ; i<pos-1;i++){
				temp = temp->next;
			}
			temp2 = temp->next;
			temp->next = temp2->next;
			delete temp2;
		}
	}
}

void Linkedlist::insert_node(){
	int pos,x,a,count= 0;
	Node *nnode = new Node;
	Node *temp;
	temp = head;
	while(temp->next != head){
		count++;
		temp = temp->next;
	}
	cout<<"Enter the data : ";
	cin>>x;
	nnode->data = x;
	nnode->next = NULL;
	cout<<"\n\n\n\n1: Insert at begining\n2: Insert at End\n3:Insert at any position\n";
	cin>>a;
	if(a==1){
		nnode->next = head;
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next= nnode;
		head = nnode;
	}
	else{
		if(a==2){
			temp->next = nnode;
			nnode->next = head;
			return;
		}
		else if(a==3){
			temp = head;
			cout<<"Enter the position : ";
			cin>>pos;
			if(pos>0 && pos<=count){
				x = 0;
			}
			else{
				cout<<"Invalid position \n";
				return;
			}
		}
		for(int i = 1;i<pos-1;i++){
			temp = temp->next;
		}
		nnode->next = temp->next;
		temp->next = nnode;
	}
}

void Linkedlist::createlist(){
	int n,b;
	cout<<"how many values do you want to enter: "; 
	cin>>n;
	Node *temp;
	for(int i = 0;i<n;i++){
		Node *nnode = new Node;
		cout<<"Enter value "<<i+1<<": ";
		cin>>b;
		nnode->data = b;
		nnode->next = NULL;
		if(head == NULL){
			head = nnode;
			nnode->next = head;
		}
		else{
			temp = head;
			while(temp->next!=head){
				temp = temp->next;
			}
			temp->next = nnode;
			nnode->next = head;
		}
	}
}

void Linkedlist::display(){
	Node *temp;
	cout<<"Values: ";
	if(head != NULL){
		temp = head;
		cout<<temp->data<<" ";
		temp = temp->next;
		while(temp!= head){
			cout<<temp->data<<" ";	
			temp = temp->next;
		}
	}
	else{
		cout<<"Empty !!!!!!!!!!!!!!\n";
	}
}


int main(){
	Linkedlist L;
	int user_input;
	bool exit = false;
	while(!exit){
		cout<<"\n\n\n\n\n1: Create list \n2: insert node \n3: display\n4: delete node\n0: exit\n";
		cin>>user_input;
		if(user_input == 1){
			L.createlist();
		}
		else if (user_input == 2) {
			L.insert_node();
		}
		else if (user_input == 3) {
			cout<<"\nLinkedlist 1: ";
			L.display();
			cout<<"\nLinkedlist 2: ";
			secondlist.display();
		}
		else if (user_input == 4) {
			L.delete_node();
		}
		else if(user_input ==  0){
			exit = true;
		}
		else {
			cout<<"invalid input\n";
		}
	}
	return 0;
}