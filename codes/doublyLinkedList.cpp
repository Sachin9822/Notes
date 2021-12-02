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
			int x;
			if (head == NULL){
				head = createNode();
			}
			else{
				cout<<"\n1: insert at beginning\n2: insert at end\n3: insert at any position\n";
				cin>>x;
				if(x == 1){
					head->prev = createNode();
					head->prev->next = head;
					head = head->prev;
				}
				else if(x == 2){
					while(temp->next != NULL){
						temp = temp->next;
					}
					temp->next = createNode();
					temp->next->prev = temp;
				}
				else if(x == 3){
					int pos;
					cout<<"\n Enter the position : ";
					cin>>pos;
					for(int i = 1;i<pos-1;i++){
						temp = temp->next;
						if(temp == NULL){
							cout<<"\n!!!!!Invalid position\n";
							return;
						}
					}
					Node *nnode = createNode();
					nnode->next = temp->next;
					temp->next->prev = nnode;
					nnode->prev = temp;
					temp->next = nnode;
				}
			}
		}

		void delete_node(){
			Node *temp = head;
			int x;
			if(head != NULL){
				cout<<"\n1: delete at beginning\n2: delete at end\n3: delete at any position\n";
				cin>>x;
				if(x == 1){
					head = head->next;
					head->prev = NULL;
				}
				else if(x == 2){
					while(temp->next!=NULL){
						temp = temp->next;
					}
					temp->prev->next = NULL;
					delete temp;
				}
				else if(x == 3){
					cout<<"\nEnter the position: ";
					cin>>x;
					for(int i = 1;i<x-1;i++){
						temp = temp->next;
						if(temp == NULL){
							cout<<"\n!!!Invalid Position\n";
							return;
						}
					}
					temp->next = temp->next->next;
					temp->next->prev = temp;
				}
			}
			else{
				cout<<"\n!!Empty\n";
			}

		}
		void display(){
			Node *temp = head;
			cout<<"List: ";
			if(head == NULL){
				cout<<"Empty\n";
				return;
			}
			while(temp->next != NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data<<endl;
		}

		/* void transverse(){ */
			/* display(); */
			/* Node *temp = head; */
			/* bool exit=false; */
			/* int x; */
			/* while(!exit){ */
			/* 	cout<<"Current Element : "<<temp->data<<endl; */
			/* 	cout<<"\n1: Next\n2: Previous\n3: exit\n"; */
			/* 	cin>>x; */
			/* 	if(x == 1){ */
			/* 		temp = temp->next; */
			/* 	} */
			/* 	else if(x == 2){ */
			/* 		temp = temp->prev; */
			/* 	} */
			/* 	else if(x == 3){ */
			/* 		exit = true; */
			/* 	} */
			/* 	if(temp== NULL){ */
			/* 		cout<<"\nNULL\n"; */
			/* 		temp = head; */ 
			/* 	} */
			/* } */
		/* } */

};

int main(){
	
	LinkedList L;
	bool exit = false;
	int inp;
	while(!exit){
		cout<<"1: Insert\n2: display\n3: delete\n4: exit\n";
		cin>>inp;
		if(inp == 1){
			int a;
			cout<<"How many data do you want to enter? ";
			cin>>a;
			for(int i = 0;i<a;i++){
				L.insertNode();
			}
		}
		else if(inp == 2){
			L.display();
		}
		else if(inp == 3){
			L.delete_node();
		}
		else if(inp == 4){
			exit = true;
		}
		
	}

	return 0;
}
