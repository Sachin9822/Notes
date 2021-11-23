#include <cstddef>
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
	void sort();
	void reverse_ll(Node *pointer);
	void reverse();
	void createlist();
	void insert_node();
	void find_node();
	void display();
	void delete_node();
};

void swap(Node *one,Node *two){
	int temp;
	temp = one->data;
	one->data = two->data;
	two->data = temp;
}

void Linkedlist::sort(){
	int min;
	Node *temp,*temp2;
	temp = head;
	while(temp->next!= NULL){
		min = temp->data;
		temp2 = temp;
		while(temp2->next != NULL){
			if(min>temp2->data){
				min = temp2->data;
				swap(temp,temp2);
			}
			temp2 = temp2->next;
		}
		if(min > temp2->data){
			min = temp2->data;
			swap(temp,temp2);
		}
		temp = temp->next;
	}
}

void Linkedlist::reverse(){
	cout<<"reversed list : ";
	reverse_ll(head);
	cout<<endl;
}

void Linkedlist::reverse_ll(Node *pointer){
	if(pointer->next == NULL){
		cout<<pointer->data<<" ";
		return;
	}
	reverse_ll(pointer->next);
	cout<<pointer->data<<" ";
}

void Linkedlist::delete_node(){
	int pos;
	Node *temp;
	Node *temp2;
	temp = head;
	while(temp->next != NULL){
		x++;
		temp = temp->next;
	}
	cout<<"1: Delete at the begining\n2: Delete at the end\n3: Delete at any position\n";
	int a;
	cin>>a;
	if(a == 1){
		head = head->next;
	}
	else{
		if(a == 2){
			pos = x+1;
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
		}
		temp = head;
		for(int i = 1 ; i<pos-1;i++){
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = temp2->next;
	}
}

void Linkedlist::insert_node(){
	int pos,x,a;
	Node *nnode = new Node;
	Node *temp;
	temp = head;
	while(temp->next != NULL){
		x++;
		temp = temp->next;
	}
	cout<<"Enter the data : ";
	cin>>x;
	nnode->data = x;
	cout<<"\n\n\n\n1: Insert at begining\n2: Insert at End\n3:Insert at any position\n";
	cin>>a;
	if(a==1){
		nnode->next = head;
		head = nnode;
	}
	else{
		if(a==2){
			pos = x-1;
		}
		else if(a==3){
			temp = head;
			cout<<"Enter the position : ";
			cin>>pos;
			if(pos>0 && pos<=x){
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
	int user_input;
	bool exit = false;
	while(!exit){
		cout<<"\n\n\n\n\n1: Create list \n2: insert node \n3: display\n4: delete node\n5: reverse Linkedlist\n6: sort\n7: exit\n";
		cin>>user_input;
		if(user_input == 1){
			L.createlist();
		}
		else if (user_input == 2) {
			L.insert_node();
		}
		else if (user_input == 3) {
			L.display();
		}
		else if (user_input == 4) {
			L.delete_node();
		}
		else if(user_input == 6){
			L.sort();
		}
		else if(user_input == 5){
			L.reverse();
		}
		else if(user_input == 7){
			exit = true;
		}
		else {
			cout<<"invalid input\n";
		}
	}
	return 0;
}

