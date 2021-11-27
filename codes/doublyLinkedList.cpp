#include<iostream>

using namespace std;

class  Node{
	public:
		int data;
		Node *next;
		Node *prev;
};

class LinkedList{
	Node *head;
	public:
		LinkedList(){
			head = NULL;
		}
		Node *createNode(){
			Node *nnode = new Node;
			int x;
			cout<<"Enter the data: ";
			cin>>x;
			nnode->data = x;
			nnode->next = NULL;
			nnode->prev = NULL;
			return nnode;
		}
		void insertNode(){
			int x,pos;
			Node *temp = head;
			if (head == NULL){
				head = createNode();
			}
			else{
				cout<<"\n1: insert at end\n2: insert at any position\n3: insert at begining\n";
				cin>>x;
				if(x == 1){
					while(temp->next != NULL){
						temp = temp->next;
					}
					temp->next = createNode();
					temp->next->prev = temp;
				}
				else if(x == 2){
				auto nnode = createNode();
					cout<<"enter the position : ";
					cin>>pos;
					for(int i = 1;i<pos-1;i++){
						temp = temp->next;
					}
					nnode->next = temp->next;
					temp->next->prev = nnode;
					temp->next = nnode;
					nnode->prev = temp;
				}
				else if(x == 3){
				auto nnode = createNode();
					nnode->next = head;
					head->prev = nnode;
					head = nnode;
				}
			}
		}
		void deleteNode(){
			int x,pos;
			Node *temp=head,*prevNode;
			cout<<"\n1: delete at end\n2: delete at any position\n3: delete at begining\n";
			cin>>x;
			if(x == 1){
				while(temp->next != NULL){
					temp = temp->next;
				}
				cout<<"data : "<<temp->data<<endl;
				prevNode = temp;
				temp->prev->next = NULL;
				delete prevNode;	
			}
			else if(x == 2){
				cout<<"Enter the position : ";
				cin>>pos;
				for(int i = 1;i<pos-1;i++){
					temp = temp->next;
				}
				prevNode = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete prevNode;
			}
			else if(x == 3){
				prevNode = head;
				head = head->next;
				head->prev = NULL;
			}
		}
		void display(){
			Node *temp = head;
			cout<<"List: ";
			while(temp->next != NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data<<endl;
		}
		void transverse(){
			display();
			Node *temp = head;
			bool exit=false;
			int x;
			while(!exit){
				cout<<"Current Element : "<<temp->data<<endl;
				cout<<"\n1: Next\n2: Previous\n3: exit\n";
				cin>>x;
				if(x == 1){
					temp = temp->next;
				}
				else if(x == 2){
					temp = temp->prev;
				}
				else if(x == 3){
					exit = true;
				}
				if(temp== NULL){
					cout<<"\nNULL\n";
					temp = head; 
				}
			}
		}
};

int main(){
	
	LinkedList L;
	L.insertNode();
	L.display();
	L.insertNode();
	L.display();
	L.insertNode();
	L.display();
	L.insertNode();
	L.display();
	L.insertNode();
	L.display();
	L.deleteNode();
	L.display();
	L.deleteNode();
	L.display();
	L.deleteNode();
	L.display();

	return 0;
}
