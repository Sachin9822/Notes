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

class deque{
	Node *front,*rear;
	public:
		deque(){
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
		void enqueue_front(){
			if(front == NULL){
				front = rear = createNode();
				return;
			}
			front->prev = createNode();
			front->prev->next = front;
			front = front->prev;
		}
		void enqueue_rear(){
			if(front == NULL){
				front = rear = createNode();
				return;
			}
			rear->next = createNode();
			rear->next->prev = rear;
			rear = rear->next;
		}
		void dequeue_front(){
			if(front== NULL){
				front = rear = NULL;
				cout<<"\ndeque is empty\n";
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
		void dequeue_rear(){
			if(front== NULL){
				front = rear = NULL;
				cout<<"\ndeque is empty\n";
				return;
			}
			cout<<"Dequeueing "<<rear->data<<endl;
			if(rear->prev != NULL){
				rear = rear->prev;
				rear->next = NULL;
			}
			else {
				front = rear = NULL;
			}
		}
		void display(){
			Node *temp = front;
			cout<<"deque: ";
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
	deque q;
	while(!exit){
		cout<<"\n1: enqueue_rear\n2: enqueue_front\n3: dequeue_rear\n4: dequeue_front\n5: display\n6: exit\n";
		cin>>user_input;
		if(user_input == 1)
			q.enqueue_rear();
		else if(user_input == 2)
			q.enqueue_front();
		else if(user_input == 3)
			q.dequeue_rear();
		else if(user_input == 4)
			q.dequeue_front();
		else if(user_input == 5)
			q.display();
		else if(user_input == 6){
			break;
		}
	}	
	
	return 0;
}
