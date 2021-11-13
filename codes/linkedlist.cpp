#include <cstddef>
#include<iostream>

using namespace std;

class Node {
	public:
	int data;
	Node *next;
};
class Linkedlist{
	Node *head;
	public:
	Linkedlist(){
		head = NULL;
	}
	~Linkedlist(){

	}
	void createlist();
	void insert_node();
	void find_node();
	void display();
	void delete_node();
};
void Linkedlist::delete_node(){
	int pos;
	Node *temp;
	Node *temp2;
	cout<<"Enter the position to delete node: ";
	cin>>pos;
	temp = head;
	for(int i = 0 ; i<pos-2;i++){
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = temp2->next;

}
void Linkedlist::insert_node(){
	int pos,x;
	Node *nnode = new Node;
	Node *temp;
	cout<<"Enter the data : ";
	cin>>x;
	nnode->data = x;
	temp = head;
	cout<<"Enter the position : ";
	cin>>pos;
	for(int i = 0;i<pos-2;i++){
		temp = temp->next;
	}
	nnode->next = temp->next;
	temp->next = nnode;
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
		}
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = nnode;
		}
	}
}
void Linkedlist::display(){
	Node *temp;
	cout<<"Values: ";
	if(head != NULL){
		temp = head;
		while(temp->next != NULL){
			cout<<temp->data<<" ";	
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
	else{
		cout<<"Empty !!!!!!!!!!!!!!\n";
	}
}

int main(){
	Linkedlist L;
	L.createlist();
	L.display();
	L.delete_node();
	L.display();
	return 0;
}

