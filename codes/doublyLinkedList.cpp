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
			Node *temp = head;
			if (head == NULL){
				head = createNode();
			}
			else{
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode();
				temp->next->prev = temp;
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
	L.transverse();

	return 0;
}
