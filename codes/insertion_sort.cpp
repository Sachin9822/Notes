#include <iostream>

using namespace std;
const int Max = 10;
class insertion_sort{
	int arr[Max];
	int smallest;
	int n;
public:
	// insertion_sort(){
	// 	arr = {1,2,3,4,5,6,7,8,9,0};
	// }
	
	void input_data();
	void sort();
	void insert(int position,int location);
	void display();
};

insertion_sort s;

void insertion_sort::insert(int position,int location){
	int temp;
	temp = arr[position];
	arr[position] = arr[location];
	arr[location] = temp;
}

void insertion_sort::input_data(){
	cout<<"Enter the length of the array: ";
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}
}
int num = 1;
void insertion_sort::sort(){
	// find the smallest element in the array
	int smallest = arr[0];
	int n1;
	for(int i = 0; i<n;i++){
		for(int j = i;j<n;j++){
			if(arr[j]<smallest){
				smallest = arr[j];
				n1 = j;
			}
		}
			smallest = arr[i];
			insert(n1,i);
			n1 = i;
			cout<<"Pass "<<num++<<" - ";
			s.display();
	}
}
void insertion_sort::display(){
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
