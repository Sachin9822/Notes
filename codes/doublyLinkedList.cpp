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
		void search(){
			Node *temp = head;
			int data_to_search;
			cout<<"Enter the data to search : ";
			cin>>data_to_search;
			while(temp!=NULL){
				if(temp->data == data_to_search){
					cout<<"\nItem Found!!!\n";
					return;
				}
				temp = temp->next;
			}
			cout<<"\nNot found\n\n";
		}

		void swap(Node *one,Node *two){
			int temp;
			temp = one->data;
			one->data = two->data;
			two->data = temp;
		}
		
		void sort(){
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
		void display_rev(Node *start){
			if(start == NULL)
				return;
			display_rev(start->next);
			cout<<start->data<<" ";
		}
		Node *get_head(){
			return head;
		}
		void setHead(Node *Head){
			head = Head;
		}
		void split();
		void merge();

};
LinkedList secondlist;

void LinkedList::merge(){
	Node *temp;
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = secondlist.get_head();
	secondlist.setHead(NULL);
}

void LinkedList::split(){
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
int main(){
	
	LinkedList L;
	bool exit = false;
	int inp;
	while(!exit){
		cout<<"1: Insert\n2: display\n3: delete\n4: search\n5: sort\n6: print reverse\n7: split\n8: merge\n9: exit\n";
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
			cout<<"LinkedList 1: ";
			L.display();
			cout<<"LinkedList 2: ";
			secondlist.display();
		}
		else if(inp == 3){
			L.delete_node();
		}
		else if(inp == 4){
			L.search();
		}
		else if(inp == 5){
			L.sort();
		}
		else if(inp == 6){
			Node *start = L.get_head();
			cout<<"Reverse: ";
			L.display_rev(start);
			cout<<endl;
		}	
		else if(inp == 7){
			L.split();
		}
		else if(inp == 8){
			L.merge();
		}
		else if(inp == 9){
			break;
		}	
	}

	return 0;
}
