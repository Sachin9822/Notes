#include <iostream>

using namespace std;
const int Max = 10;
class selection_sort{
	int arr[Max];
	int smallest;
	int n;
public:
	// selection_sort(){
	// 	arr = {1,2,3,4,5,6,7,8,9,0};
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
	for(int i = 0; i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int test[] = {1,2,3,4};
	s.input_data();
	s.sort();
	cout<<"Sorted array : ";
	s.display();
	return 0;
}