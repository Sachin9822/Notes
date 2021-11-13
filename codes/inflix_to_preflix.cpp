#include <iostream>
#include<string>
#include <bits/stdc++.h>

using namespace std;
const int Max = 1000;
class inflix_2_preflix{
	string ans;
	char Preflix[Max];
	char simple_stack[Max];
	int evaluate_ans[Max];
	int top,top1,top3;
	bool incorrect;
	string user_input;
	string opening_brackets;
	string closing_brackets;
	string operators;
public: 
	inflix_2_preflix(){
		closing_brackets = "({[";
		opening_brackets = ")}]";
		operators = "+-/*^%";
		top = -1;
		top1 = -1;
		top3 = -1;
		incorrect = false;
	}
	void input_data();
	void parenthesis(char input);
	int signs(char input);
	void convert();
	int precedence(char operato);
	void evaluate();
};
inflix_2_preflix ip;


void inflix_2_preflix::evaluate(){
	int top3=-1;
	int evaluate_ans[20];
	for(int i = ans.length()-1;i>-1;i--){			
		if(ans[i]=='+'){
			evaluate_ans[top3-1]=evaluate_ans[top3]+evaluate_ans[top3-1];
			top3 --;
		}
		else if(ans[i]=='-'){
			evaluate_ans[top3-1]=evaluate_ans[top3]-evaluate_ans[top3-1];
			top3 --;
			 
		}
		else if(ans[i]=='*'){
			evaluate_ans[top3-1]=evaluate_ans[top3]*evaluate_ans[top3-1];
			top3 --;
			 
		}
		else if(ans[i]=='/'){
			evaluate_ans[top3-1]=evaluate_ans[top3] / evaluate_ans[top3-1];
			top3 --;
			 
		}
		else if(ans[i]=='%'){
			evaluate_ans[top3-1]=evaluate_ans[top3]%evaluate_ans[top3-1];
			top3 --;
		}
		else{
			evaluate_ans[++top3]=(int)(ans[i]-'0');
		}
	}
		cout<<"Evaluated ans: "<<evaluate_ans[0]<<endl;
}

int inflix_2_preflix::precedence(char operato){
	if(operato == '^')
		return 3;
	else if (operato == '*' || operato == '/' || operato == '%')
		return 2;
	else if (operato == '+' || operato == '-')
		return 1;
	else{
		return 0;
	}
}
void inflix_2_preflix::parenthesis(char input){
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
				if(precedence(simple_stack[top])==precedence(simple_stack[top-1])){
					Preflix[++top1] = simple_stack[top-1];
					simple_stack[top-1] = simple_stack[top];
					top -=1;
				}

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
int inflix_2_preflix::signs(char input){
	for(int i = 0 ; i<operators.length();i++){
		if(input == operators[i]){
			return 1;
		}
	}
	return 0;
}
void inflix_2_preflix::input_data(){
	cout<<"Enter the Expression: \n";
	user_input = "A^B*C-D+E/F/(G+H)";
	// user_input = "((A+B)*C–(D–E))^(F+G)";
	user_input = "A-B/(C*D^E)";
	// user_input = "(a+b^c^d)*(e+(f/d))";
	user_input = "3-6*7+2/4*5-8";
	// user_input = "(A-B)/((D+E)*F)";
	// user_input = "((A+B)/D)^((E-F)*G)";
	// cin>>user_input;
}
void inflix_2_preflix::convert(){
	for(int i =user_input.length()-1; i>-1;i--){
		ip.parenthesis(user_input[i]);
		
	}
	if(!incorrect){
		cout<<"Preflix : ";
		for(int j = 0;j<=top;j++){
			cout<<simple_stack[j];
			ans += simple_stack[j];
		}
		for(int i =top1;i>-1;i--){
			cout<<Preflix[i];
			ans += Preflix[i];
		}
		cout<<endl;

		
		// cout<<ans<<endl;
	}	

}

int main(){
	int temp=1;
	ip.input_data();
	ip.convert();
	cout<<"Press 1 to evaluate\n";
	cin>>temp;
	if(temp==1){
	ip.evaluate();
	}
	return 0;
}
