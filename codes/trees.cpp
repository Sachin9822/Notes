#include <cctype>
#include<iostream>
#include <type_traits>

using namespace std;

class Node{
	public:
		int data;
		Node *left,*right;
};
class Tree{
	int count;
	public:
		Tree(){
			count= 1;
		}
		Node * createNode(){
			count *=2;
			int data;
			char user_input;
			Node *temp = new Node;
			cout<<"Enter the data: ";
			cin>>data;
			temp->data = data; 
			cout<<"Do you want to create left Node "<<count<<" : y/n\n";
			cin>>user_input;
			if(tolower(user_input) == 'y'){
				temp->left = createNode();
			}
			count ++;
			cout<<"Do you want to create right Node "<<count<<" : y/n\n";
			cin>>user_input;
			if(tolower(user_input) == 'y'){
				temp->right = createNode();
			}
			count ++;
			count -=2;
			count /=2;
			return temp;
		}
		void postorder(Node *root){
			if(root == NULL){
				return;
			}
			postorder(root->left);
			postorder(root->right);
			cout<<root->data<<" ";

		}
		void inorder(Node *root){
			if(root == NULL){
				return;
			}
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
		}
		void preorder(Node *root){
			if(root == NULL)
				return;
			cout<<root->data<<" ";
			preorder(root->left);
			preorder(root->right);
		}
};
int main(){
	Tree t;
	auto root = t.createNode();
	cout<<"Inorder : ";
	t.inorder(root);
	cout<<"\nPreorder : ";
	t.preorder(root);
	cout<<"\nPostorder : ";
	t.postorder(root);
	return 0;
}
