#include<iostream>

using namespace std;
class Node {
	public:
		int data;
		Node *next,*prev;
		Node(){
			next = NULL;
			prev = NULL;
		}
};

class Stack{
	Node *head;
	Node *top;
	public:
		Stack(){
			head = top = NULL;
		}
		Node *createNode(){
			Node *nnode = new Node;
			int da;
			cout<<"Enter the data: ";
			cin>>da;
			nnode->data = da;
			return nnode;
		}
		void push(){
			if(head == NULL){
				head = top = createNode(); 
				return;
			}
			top->next=createNode();
			top->next->prev = top;
			cout<<"\n\npushing to stack\n";
			top = top->next;
		}
		void pop(){
			Node *temp;
			if(top== NULL){
				cout<<"\nStack empty!!!!!!\n";
				return;
			}
			cout<<"Poping "<<top->data<<endl;
			temp = top;
			top = top->prev;
			delete temp;
		}
		void display(){
			Node *temp = head;
			cout<<"Stack : ";
			if(top == NULL){
				cout<<"Empty!!\n";
				return;
			}
			while(temp!=top){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<temp->data<<"\n "; 

		}

};

int main(){
	Stack s;
	bool exit = false;
	int user_input;
	while(!exit){
		cout<<"\n1: push\n2: pop\n3: display\n4: exit\n";
		cin>>user_input;
		if(user_input == 1){
			s.push();
		}
		else if(user_input== 2 ){
			s.pop();
		}
		else if(user_input == 3){
			s.display();
		}
		else if(user_input == 4){
			exit = true;
		}

	}
	return 0;
}
