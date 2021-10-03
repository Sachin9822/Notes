# C++

> Sachin Padwalkar | 13-9-21
-------------------------
## Table of contents
- [Bubble Sort](https://github.com/Sachin9822/Notes/blob/master/cpp.md#bubble-sort)
- [Selection Sort](https://github.com/Sachin9822/Notes/blob/master/cpp.md#selection-sort)
- [Stack](https://github.com/Sachin9822/Notes/blob/master/cpp.md#stack)
- [Programe to check matching parenthesis](https://github.com/Sachin9822/Notes/blob/master/cpp.md#matching-parenthesis)
- [Inflix to Postflix conversion](https://github.com/Sachin9822/Notes/blob/master/cpp.md#inflix-to-postflix)
- [Inflix to Preflix conversion](https://github.com/Sachin9822/Notes/blob/master/cpp.md#inflix-to-preflix)

---------------------------------------------------------------------

* To reverse a string:
````c++
#include<bits/stdc++.h>

string p = "Sachin";
reverse(p.begin(),p.end());
````
* To remove a perticular character in string
````c++
string s = "Sachin";
s.erase(s.begin() + 3) // Output: Sahin
````
`tolower()` - converts to lowecase ascii  

`toupper()` - converts to uppercase ascii   

`tolower(chr,locale()) ` - converts to lowecase char  


* Square root in c++
````c++
#include <cmath>
#include <iomanip>

sqrtf() // returns float
````

## Stack
```c++
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
	int is_empty();
	int is_full();
};

int stack::is_empty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

int stack::is_full(){
	if(top == Max)
		return 1;
	else 
		return 0;
}
void stack::push(int a){
	if(top<Max-1){
		
		top+=1;
		arr[top] = a;
		cout<<a<<" pushed to stack\n";
	}
	else{
		cout<<"Stack is full\n";
		
	}
}

void stack::pop(){
	if(top >= 0){
		cout<<"Removing "<<arr[top]<<endl;
		top -=1;
	}else{
		cout<<"Stack is empty\n";
		
	}
}
int main(){

	stack s;
	for(int i = 1; i<=Max+1;i++){
		
		s.push(i);
	}
	for(int j = 0; j<=Max;j++){
		s.pop();
	}
	return 0;
}
```

## Bubble Sort

```c++
#include <iostream>
using namespace std;

class bubble_sorting{
	int arr[100];
	int n=0;

public:
	void input();
	void display();
	void sort();
};

void bubble_sorting::input(){
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i = 0; i<n;i++){
		cin>>arr[i];
	}
}

void bubble_sorting::display(){
	cout<<"Sorted array : ";
	for(int i = 0; i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void bubble_sorting::sort(){
	int temp;
	cout<<"Sorting.................................................\n";
	for(int i = 0; i<n-1 ; i++)
		for(int j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
}

int main(){
	bubble_sorting s;
	s.input();
	s.sort();
	s.display();
	return 0;
}
```
## Selection Sort
```c++
#include <iostream>

using namespace std;
const int Max = 10;
class selection_sort{
	int arr[Max] ;
	int smallest;
	int n;
public:
	// selection_sort(){
	// 	arr[Max] = {1,2,3,4,5,6,7,8,9,0};
	// }
	
	void input_data();
	void sort();
	void insert(int position,int location);
	void display();
};

selection_sort s;
/* 1 3 5 2 4
   0 1 2 3 4
   position = 3
   location = 1
   store arr[position]
   2 1 
   3 2
*/
void selection_sort::insert(int position,int location){
	int temp;
	temp = arr[position];
	for(int i = position; i>=location;i--){
		arr[i] = arr[i-1];
	}
	arr[location] = temp;
}

void selection_sort::input_data(){
	cout<<"Enter the length of the array: ";
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}
}
int num = 0;
void selection_sort::sort(){
	for(int i =1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(arr[j]>arr[i]){
				insert(i,j);
				cout<<"Pass "<<num++<<" - ";
				s.display();
			}
		}
	}
}
void selection_sort::display(){
	cout<<"Sorted array: ";
	for(int i = 0; i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	s.input_data();
	s.sort();
	s.display();
	return 0;
}
```


## Matching Parenthesis
```c++
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
```

## Inflix to Postflix
```c++
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int Max = 1000;
class inflix_2_postflix{
	char Postflix[Max];
	char simple_stack[Max];
	int top,top1;
	bool incorrect;
	string user_input;
	string opening_brackets;
	string closing_brackets;
	string operators;
public: 
	inflix_2_postflix(){
		opening_brackets = "({[";
		closing_brackets = ")}]";
		operators = "+-/*^";
		top = -1;
		top1 = -1;
		incorrect = false;
	}
	void input_data();
	void parenthesis(char input);
	int signs(char input);
	void convert();
	int precedence(char operato);
};
inflix_2_postflix ip;

int inflix_2_postflix::precedence(char operato){
	if(operato == '^')
		return 3;
	else if (operato == '*' || operato == '/')
		return 2;
	else if (operato == '+' || operato == '-')
		return 1;
	else{
		return 0;
	}
}
void inflix_2_postflix::parenthesis(char input){

	for(int i = 0 ; i<3;i++){
		if(input == opening_brackets[i]){
			simple_stack[++top] = input;
			break;
		}
		else if(input == closing_brackets[i]){
			if(top > -1){
// (+

				for(int z = top; z>-1;z--){
					if(simple_stack[z]==opening_brackets[i]){
						top -=1;
						break;
					}
					else{
						top -=1;
						
						Postflix[++top1] = simple_stack[z];
						
					}
				}

			}
			else{
				cout<<"Invalid Expression \n";
				incorrect = true;
				break;
			}
		}
		else if(signs(input)){
			if(precedence(simple_stack[top]) < precedence(input)){
			simple_stack[++top] = input;
			}
			else{
				Postflix[++top1] = simple_stack[top--];
				simple_stack[++top] = input;

			}
			break;
		}
		else{
			if(input != ')'){
			Postflix[++top1] = input;
			}
			break;
		}
	}
}
int inflix_2_postflix::signs(char input){
	for(int i = 0 ; i<5;i++){
		if(input == operators[i]){
			return 1;
		}
	}
	return 0;
}
void inflix_2_postflix::input_data(){
	cout<<"Enter the Expression: \n";
	// user_input = "A^B*C–D+E/F/(G+H)";
	// user_input = "((A+B)*C–(D–E))^(F+G)";
	user_input = "A–B/(C*D^E)";
	// user_input = "(a+b^c^d)*(e+f/d))";
	// user_input = "3 – 6 * 7 + 2 / 4 * 5 – 8";
	// user_input = "(A – B) / ((D + E) * F)";
	// user_input = "((A + B) / D) ^((E – F) * G)";

	// cin>>user_input;
}
void inflix_2_postflix::convert(){
	for(int i = 0; i<user_input.length();i++){
		ip.parenthesis(user_input[i]);
		
	}
	if(!incorrect){
		cout<<"Postflix : ";
		cout<<Postflix;
		for(int j = top;j>-1;j--){
			cout<<simple_stack[j];
		}
		cout<<endl;
	}	
}

int main(){
	ip.input_data();
	ip.convert();
	return 0;
}
```

## Inflix to Preflix
```c++
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int Max = 1000;
class inflix_2_postflix{
	char Preflix[Max];
	char simple_stack[Max];
	int top,top1;
	bool incorrect;
	string user_input;
	string opening_brackets;
	string closing_brackets;
	string operators;
public: 
	inflix_2_postflix(){
		closing_brackets = "({[";
		opening_brackets = ")}]";
		operators = "+-/*^";
		top = -1;
		top1 = -1;
		incorrect = false;
	}
	void input_data();
	void parenthesis(char input);
	int signs(char input);
	void convert();
	int precedence(char operato);
};
inflix_2_postflix ip;

int inflix_2_postflix::precedence(char operato){
	if(operato == '^')
		return 3;
	else if (operato == '*' || operato == '/')
		return 2;
	else if (operato == '+' || operato == '-')
		return 1;
	else{
		return 0;
	}
}
void inflix_2_postflix::parenthesis(char input){
	for(int i = 0 ; i<3;i++){
		if(input == opening_brackets[i]){
			simple_stack[++top] = input;
			break;
		}
		else if(input == closing_brackets[i]){
			if(top > -1){
// (+

				for(int z = top; z>-1;z--){
					if(simple_stack[z]==opening_brackets[i]){
						top -=1;
						break;
					}
					else{
						top -=1;
						
						Preflix[++top1] = simple_stack[z];
						
					}
				}

			}
			else{
				cout<<"Invalid Expression \n";
				incorrect = true;
				break;
			}
		}
		else if(signs(input)){
			if(precedence(simple_stack[top]) < precedence(input)){
			simple_stack[++top] = input;
			}
			else{
				Preflix[++top1] = simple_stack[top--];
				simple_stack[++top] = input;

			}
			break;
		}
		else{
			if(input != '('){
			Preflix[++top1] = input;
			}
			break;
		}
	}
}
int inflix_2_postflix::signs(char input){
	for(int i = 0 ; i<5;i++){
		if(input == operators[i]){
			return 1;
		}
	}
	return 0;
}
void inflix_2_postflix::input_data(){
	cout<<"Enter the Expression: \n";
	// user_input = "A^B*C–D+E/F/(G+H)";
	// user_input = "((A+B)*C–(D–E))^(F+G)";
	user_input = "A-B/(C*D^E)";
	// user_input = "(a+b^c^d)*(e+f/d))";
	// user_input = "3 – 6 * 7 + 2 / 4 * 5 – 8";
	user_input = "(A–B)/((D+E)*F)";
	// user_input = "((A + B) / D) ^((E – F) * G)";

	// cin>>user_input;
}
void inflix_2_postflix::convert(){
	for(int i =user_input.length()-1; i>-1;i--){
		ip.parenthesis(user_input[i]);
		
	}
	if(!incorrect){
		cout<<"Preflix : ";
		for(int j = top;j>-1;j--){
			cout<<simple_stack[j];
		}
		for(int i =top1;i>-1;i--){
			cout<<Preflix[i];
		}
		cout<<endl;
	}	
}

int main(){
	ip.input_data();
	ip.convert();
	return 0;
}
```


