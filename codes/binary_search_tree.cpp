
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
	void delete_node(){
		int ele;
		cout<<"Enter the element to delete : ";
		cin>>ele;
		Node *temp = head;
				if(temp->data == ele){
					cout<<"Deleted "<<temp->data<<endl;
					if(temp->right != NULL){
						head = temp->right;
						return;
					}
					else {
						head = temp->left;
						return;
					}
				}
		while(temp!=NULL){
			if(temp->data>ele){
				if(temp->right->data == ele){
					cout<<"Deleted "<<temp->right->data<<endl;
					if(temp->right->right != NULL){
						temp->right = temp->right->right;
						return;
					}
					else {
						temp->right = temp->right->left;
						return;
					}
				}
				temp = temp->right;
			}	
			else if(temp->data<ele){
				if(temp->left->data == ele){
					cout<<"Deleted "<<temp->left->data<<endl;
					if(temp->left->right != NULL){
						temp->left = temp->left->right;
						return;
					}
					else {
						temp->left = temp->left->left;
						return;
					}
				}
				temp=temp->left;
			}
		}

		
	};
  void create_bst(){
    int count;
    cout<<"how many values do you want to enter: ";
    cin>>count;
    for(int i = 0;i<count;i++){
      Node *nnode = new Node;
      cout<<"Enter the data : ";
      cin>>nnode->data;
      if(head == NULL){
	head = nnode;
      }
      else {
	Node *temp = head;
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
  }
  void insert(){
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
      else if (nnode->data == temp->data) {
      cout<<"Duplicate node\n";
      return;
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
  int user_input;
  bool exit = false;
  BST b;
  while(!exit){
    cout<<"1: create \n2: Insert\n3: print\n4: search\n5: exit\n";
    cin>>user_input;
    if(user_input == 1)
      b.create_bst();
    else if(user_input == 2)
      b.insert();
    else if(user_input == 3){
      Node *head = b.getHead();
      cout<<"inorder: ";
      b.inorder(head);
      cout<<"\n postorder: ";
      b.decending(head);
      cout<<endl;
    }
    else if(user_input == 4){
      cout<<"Enter the data to search: ";
      int se;
      cin>>se;
      b.search(se);
    }
    else if(user_input == 6){
			b.delete_node();
		}
    else if(user_input == 5)
      exit = true;
  }
  return 0;
}
