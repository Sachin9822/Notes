#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *next,*prev;
		Node(){
			next = prev = NULL;
		}
};

class Queue{
	Node *front,*rear;
	public:
		Queue(){
			 front = rear = NULL;
		}
		Node *createNode(){
			int da;
			Node *nnode = new Node;
			cout<<"Enter the data: ";
			cin>>da;
			nnode->data = da;
			return nnode;
		}
		void enqeue(){
			if(front == NULL){
				front = rear = createNode();
				return;
			}
			rear->next = createNode();
			rear->next->prev = rear;
			rear = rear->next;
		}
		void dequeue(){
			if(front== NULL){
				front = rear = NULL;
				cout<<"\nQueue is empty\n";
				return;
			}
			cout<<"Dequeueing "<<front->data<<endl;
			if(front->next != NULL){
				front = front->next;
				front->prev = NULL;
			}
			else {
				front = rear = NULL;
			}
		}
		void display(){
			Node *temp = front;
			cout<<"Queue: ";
			if(front == NULL){
				cout<<"Empty!!!\n";
				return;
			}
			while(temp != rear){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data<<" ";
		}
};

int main(){
	bool exit = false;
	int user_input;
	Queue q;
	while(!exit){
		cout<<"\n1: enqeue\n2: dequeue\n3: display\n4: exit\n";
		cin>>user_input;
		if(user_input == 1)
			q.enqeue();
		else if(user_input == 2)
			q.dequeue();
		else if(user_input == 3)
			q.display();
		else if(user_input == 4)
			exit = true;
	}	
	
	return 0;
}
