#include <iostream>

using namespace std;

class palindrome{
	string characters;
	int top;
	char arr[10];
public:
	palindrome(){
		top = -1;
		characters = "madams";
	}
	void check(){
		for(int i =0;i<characters.length();i++){
			if(top<9){	
			arr[++top] = characters[i];
			}
		}
		int ans = 0;
		for(int j = 0;j<characters.length();j++){
			if(top >-1){
				// cout<<arr[top]<<characters[j]<<endl;
				if(arr[top--]==characters[j]){
					ans = 1;
				}
				else {
					ans = 0;
					break;
				}
			}
		}
		if(ans){
			cout<<"palindrome\n";
		}
		else
			cout<<"Not palindrome\n";
	}
};

int main(){
	palindrome p;
	p.check();
	return 0;
}