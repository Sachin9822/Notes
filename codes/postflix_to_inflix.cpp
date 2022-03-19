#include<iostream>

using namespace std;

#define MAX 100

class inflix2postflix{
	string arr[MAX];
	int top;
	string user_input;
	
public:
	inflix2postflix(){
		top = -1;
	}
	bool operator_(char ch){
		string operato = "+-%/*^";
		for(int i = 0; i<operato.length();i++){
			if(ch == operato[i])
				return true;
			}
		return false;
	}
	void input(){
		cout<<"Enter the Postflix expression: ";
		cin>>user_input;
		/* user_input = "AB-*"; */
		/* user_input = "ABC*-DE-F*G/H/+"; */
		/* user_input = "AB+C/D*EF^-"; */
		/* user_input = "ABC^-DE*FG+/+"; */
		/* user_input = "ABC*-DE-F*G/H/+"; */
		/* user_input = "AB+C/D*EF^-"; */
	}
 	void convert();
 	void display(){
 		cout<<arr[0]<<"\n";
 	}
};
	inflix2postflix t;

void inflix2postflix::convert(){
 		for(int i = 0;i<user_input.length();i++){
 			// 	cout<<"top : ";
 			// 	for(int k = top;k>-1;k--){
 			// 		cout<<arr[top-k];
 			// 	}
 			// 	cout<<endl;
 			// cout<<"arr = ";
 			// t.display();
 			// cout<<"\n"<<user_input[i]<<endl;
 			// cout<<endl;
 			if(operator_(user_input[i])){
 				if(top>0){
 				string temp = "("+arr[top-1]+user_input[i]+arr[top]+")";
 				arr[top---1] = temp;
 				// cout<<"temp: "<<temp<<endl;
 				}
 				else
 					cout<<"empty\n";
 			}
 			else{
 				arr[++top] = user_input[i];
 			}
 		}
 	}

int main(){
	t.input();
	t.convert();
	cout<<"\nInflix : ";
	t.display();
	return 0;
}
