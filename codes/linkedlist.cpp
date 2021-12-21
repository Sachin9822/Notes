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
	void split();
	void merge();
	void reverse_link();
	void reverse();
	void createlist();
	void insert_node();
	void find_node();
	void display();
	void delete_node();
	void setHead(Node *o){
		head = o;
	}
	Node* gethead(){
		return head;
	}
};

Linkedlist secondlist;
void Linkedlist::find_node(){
	int s; 
	cout<<"Enter the node to search: ";
	cin>>s;
	Node *temp = head;
	while(temp!=NULL){
		if(temp->data == s){
			cout<<"\nFound\n";
			return;
		}
		temp = temp->next;
	}
	cout<<"\nNot found\n";
}

void Linkedlist::merge(){
	Node *temp;
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = secondlist.gethead();
	secondlist.setHead(NULL);
}

void Linkedlist::split(){
	int position;
	Node *second;
	Node *temp;
	cout<<"Enter the position to split: ";
	cin>>position;
	temp = head;
	for(int i = 1 ;i<position;i++){
		temp= temp->next;	
	}
	second = temp->next;
	temp->next = NULL;
	secondlist.setHead(second);
}

void Linkedlist::reverse_link(){
	Node *x,*current,*prev;
	current = prev = NULL;
	current = head;
	while(current != NULL){
		x = current->next;
		current->next = prev;
		prev = current;
		current = x;
	}
	head = prev;
	cout<<"\n\nReversed List Successfully !!!!!!!!!\n\n";
}

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
	x=0;
	int pos;
	Node *temp;
	Node *temp2,*prevNode;
	temp = head;
	while(temp->next != NULL){
		x++;
		temp = temp->next;
	}
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
		temp->next = temp->next->next;
	}
}

void Linkedlist::insert_node(){
	int pos,x,a;
	Node *nnode = new Node;
	Node *temp;
	temp = head;
	cout<<"Enter the data : ";
	cin>>x;
	nnode->data = x;
	nnode->next = NULL;
	cout<<"\n\n\n\n1: Insert at begining\n2: Insert at End\n3:Insert at any position\n";
	cin>>a;
	if(a==1){
		nnode->next = head;
		head = nnode;
	}
	else{
		if(a==2){
			while(temp->next!= NULL ){
				temp = temp->next;
			}
			temp->next = nnode;
			return;
		}
		else if(a==3){
			temp = head;
			cout<<"Enter the position : ";
			cin>>pos;
		}
		for(int i = 1;i<pos-1;i++){
			temp = temp->next;
			if(temp == NULL){
				cout<<"Invalid Position\n";
				return;
			}
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
		while(temp != NULL){
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
		cout<<"\n\n\n\n\n1: Create list \n2: insert node \n3: display\n4: delete node\n5: print reverse \n6: sort\n7: reverse Linkedlist \n8: split\n9: merge\n10: search\n11: exit\n";
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
		else if(user_input == 6){
			L.sort();
		}
		else if(user_input == 5){
			L.reverse();
		}
		else if(user_input == 7){
			L.reverse_link();
		}
		else if(user_input == 8){
			L.split();
		}
		else if(user_input == 9){
			L.merge();
		}
		else if(user_input == 10)
			L.find_node();
		else if(user_input == 11){
			exit = true;
		}
		else {
			cout<<"invalid input\n";
		}
	}
	return 0;
}
