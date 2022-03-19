#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *left,*right;
		Node(){
			right = left= NULL;
		}
};

class AVL{
	Node *temp2;
	Node *head;
	public:
	AVL(){
		head = NULL;
	}
	int height(Node *node){
		int left_height = 0,right_height = 0;
		// counting left side height 
		Node *temp = node;
		while(temp!=NULL){
			left_height++;
			temp = temp->left;
		}
		//counting right side height 
		temp = node;
		while(temp!=NULL){
			right_height++;
			temp = temp->right;
		}
		return max(left_height,right_height);
	}
	void inorder(Node *node){
		if(node == NULL){
			return;
		}
		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}
	Node *rotate(Node *parent,int h){
		Node *temp;
		if(h==2){
			temp = parent->left->right;
			parent->left->right = parent;
			parent = parent->left;	
			parent->right->left = temp;
			return parent;
		}	
		else if(h==-2){
			temp = parent->right->left;
			parent->right->left = parent;
			parent = parent->right;	
			parent->left->right = temp;
			return parent;
		}
		else 
			return parent;
	}
	Node *getHead(){return head;}
	void createavl(){
		int d;
		Node *nnode = new Node;
		cout<<"Enter the data: ";
		cin>>nnode->data;
		head = nnode;
		
	}
	void insert(Node *start,int d){
		int h;
		Node *temp;
		if(start == NULL){
			Node *nnode = new Node;
			nnode->data = d;
			start = nnode; 
			cout<<"Data you enter is stored: "<<start->data<<endl;
			return;
		}
		else{
			if(d>=start->data){
				if(start->right != NULL){
				insert(start->right, d);
					temp2 = start;
				}
				else{
					Node *nnode = new Node;
					nnode->data = d;
					start->right = nnode;

					return;
				}
				h = height(start->left)-height(start->right);
				start->right = rotate(start, h);
				cout<<h<<" height \n";
			}else {
					if(start->left != NULL){
					temp2 = start;
				insert(start->left, d);
				}
					else{
					Node *nnode = new Node;
					nnode->data = d;
					start->left = nnode;
					return;
				}
				h = height(start->left)-height(start->right);
				start->left = rotate(start, h);
			}
		}

	}
};

int main(){
	AVL a;
	bool exit = false;
	int data;
	int user_input;
	while (!exit) {
		cout<<"1: Insert data\n2: display (inorder)\n3: create\n";
		cin>>user_input;
		if(user_input == 1){
			int times;
			cout<<"how many data do you want to enter : ";
			cin>>times;
			for(int i = 0;i<times;i++){
				cout<<"Enter data: ";
				cin>>data;
				a.insert(a.getHead(), data);	
			}
		}
		else if (user_input==2) {
			cout<<"Head is "<<a.getHead()->data<<endl;
			cout<<"Inorder: ";
			a.inorder(a.getHead());
			cout<<endl;
		}
		else if (user_input == 3) {
			a.createavl();
		}
	}
	return 0;
}
