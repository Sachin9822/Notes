#include<iostream>

using namespace std;
struct node {
	int num;
	int *n;
};

int main(){
	int i =110;
	node n1;
	n1.num = 10;
	n1=>n= &i;
	return 0;
}
