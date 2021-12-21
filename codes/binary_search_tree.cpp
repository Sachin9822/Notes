#include<iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *left,*right;
	Node(){
		left = right = NULL;
	}
};
class BST{
	Node* head;
	public:
	BST(){
		head = NULL;
	}
	void search(int value){
		Node *temp = head;
		while(temp != NULL){
		if(value > temp->data){
			if(temp->right == NULL){
				cout<<"\nNot found \n";
				return;
			}
			temp = temp->right;
		}
		else if(value == temp->data){
			cout<<"\nItem Found!!!!\n";
			return;
		}
		else{
			if(temp->left == NULL){
				cout<<"\nNot Found\n";
				return;
			}
			temp = temp->left;
		}
		}
	}
	void take_input(){
		if(head == NULL){
			Node *nnode = new Node;
			cout<<"Enter the data : ";
			cin>>nnode->data;
			head = nnode;
		}
		else{
			Node *nnode = new Node;
			cout<<"Enter the data: ";
			cin>>nnode->data;
			Node *temp=head;
			while(temp != NULL){
				if(nnode->data > temp->data){
					if(temp->right == NULL){
						temp->right = nnode;
						break;
					}
					temp = temp->right;
					
				}
				else{
					if(temp->left == NULL){
						temp->left = nnode;
						break;
					}
					temp = temp->left;
				}
			}
		}
	}
	Node *getHead(){
		return head;
	}
	void inorder(Node *next){
		if(next == NULL){
			return;
		}
		inorder(next->left);
		cout<<next->data<<" ";
		inorder(next->right);
	}
	void decending(Node *next){
		if(next == NULL)
			return;
		decending(next->right);
		cout<<next->data<<" ";
		decending(next->left);
	}
};
int main(){
	BST b;
	int times;
	cout<<"how many values do you want to enter: ";
	cin>>times;
	for(int i = 0;i<times;i++)
		b.take_input();
	Node *head = b.getHead();
	b.inorder(head);
	cout<<endl;
	b.decending(head);
	cout<<"Enter the data to search: ";
	int se;
	cin>>se;
	b.search(se);
	cout<<"Enter the data to search: ";
	cin>>se;
	b.search(se);
	return 0;
}
