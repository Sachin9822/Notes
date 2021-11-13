#include <iostream>

using namespace std;
const int Max = 100;
const string right_p = ")}]";
const string left_p = "({[";
class Char_stack{
	char arr[Max];
	int top;

public:
	Char_stack(){
		top = -1;
	}
	void pop();
	void push(char a); 
	bool is_empty();
	bool is_full();
	int check_parenthesis(string a);
};
Char_stack c;
int Char_stack::check_parenthesis(string a){
	for(int i = 0; i<a.length(); i++){
		for(int j = 0; j<3;j++){
			if(a[i] == right_p[j]){
				if(top == -1){
					cout<<a[i]<<" Right parenthesis are more \n";
					return 0;
				}
				
				if(arr[top] == left_p[j]){
					c.pop();
				}
				else{
					cout<<"Mismatching parenthesis \n";
					return 0;
				}
				
			}
			else if(a[i] == left_p[j]){				
				c.push(a[i]);
			}
		}
	}
	if(top == -1){
		cout<<"Matching parenthesis \n";
		return 1;
	}
	else{
		cout<<arr[top]<<" Left parenthesis are more \n";
		return 1;
	}
}

bool Char_stack::is_empty(){
	if(top == -1)
		return true;
	else
		return false;
}

bool Char_stack::is_full(){
	if(top == Max)
		return true;
	else 
		return false;
}
void Char_stack::push(char a){
	if(!is_full()){
		
		top+=1;
		arr[top] = a;
		// cout<<a<<" pushed to Char_stack\n";
	}
	else{
		cout<<"Stack is full\n";
		
	}
}

void Char_stack::pop(){
	if(!is_empty()){
		// cout<<"Removing "<<arr[top]<<endl;
		top -=1;
	}else{
		cout<<"Stack is empty\n";
		
	}
}

int main(){
	string user_input;
	cout<<"Enter the Expression : ";
	cin>>user_input;
	
	c.check_parenthesis(user_input);
	return 0;
}