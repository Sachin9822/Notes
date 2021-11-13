#include <iostream>

using namespace std;
const int Max = 10;
class stack{
	int arr[Max];
	int top;

public:
	stack(){
		top = -1;
	}
	void pop();
	void push(int a); 
	bool is_empty();
	int is_full();
	void display();
};

void stack::display(){
	cout<<"---------------------------------------------------------\n\n\nstack: ";
	for(int i = 0;i<=top;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n\n----------------------------------------------------------"<<endl;
}
bool stack::is_empty(){
	if(top == -1)
		return true;
	else
		return false;
}

int stack::is_full(){
	if(top == Max-1)
		return 1;
	else 
		return 0;
}
void stack::push(int a){
	if(!is_full()){
		top+=1;
		arr[top] = a;
		cout<<a<<" pushed to stack\n";
	}
	else{
		cout<<"Stack is full\n";
		
	}
}

void stack::pop(){
	if(!is_empty()){
		cout<<"Removing "<<arr[top]<<endl;
		top -=1;
	}else{
		cout<<"Stack is empty\n";
		
	}
}

void help(){
	cout<<"\n\n\n\n\n1: To push \n2: To pop\n3: View the stack\n4: To exit\n\n";
}
int main(){

	stack s;
	int user_inpu;
	bool exit = false;
	while(!exit){
		help();
		cin>>user_inpu;
		if(user_inpu == 1){
			cout<<"Enter number of value you want to push: ";
			int n;
			int temp;
			cin>>n;
			for(int i =0;i<n;i++){
				cin>>temp;
				s.push(temp);
			}
		}
		else if(user_inpu == 2){
			int n;
			cout<<"How many values do you want to pop?\n";
			cin>>n;
			for(int i = 0;i<n;i++)
				s.pop();
		}
		else if(user_inpu == 3){
			s.display();
		}
		else if(user_inpu == 4){
			exit = true;
		}
		else{
			cout<<"Invalid Input \n";
		}
	}
	return 0;
}