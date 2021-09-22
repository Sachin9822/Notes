# C++

> Sachin Padwalkar | 13-9-21
-------------------------
## Table of contents
- [Bubble Sort](https://github.com/Sachin9822/Notes/blob/master/cpp.md#bubble-sort)
- [Stack](https://github.com/Sachin9822/Notes/blob/master/cpp.md#stack)

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
