#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *left,*right;
		Node(){
			left = NULL;
			right = NULL;
		}
};

class BinaryTree{
	int count;
	public:
		BinaryTree(){
			count = 1;
		}
		Node *InsertData(){
			int data,data2,exit;
			Node *temp = new Node;
			cout<<"Enter the data: ";
			cin>>data;
			temp->data = data;
			cout<<"Enter the data: ";
			cin>>data2;
			cout<<"\n1: to proceed\n2: done\n";
			cin>>exit;
			if(exit == 2){
				return temp;
			}
			else {
				if(data2 > data){
					if(temp->right == NULL)
						temp->right = InsertData();
				}
				else{
					if(temp->left == NULL)
						temp->left = InsertData();
				}
			}
		}
};
int main(){
	BinaryTree B;
	auto root = B.InsertData();
	return 0;
}
