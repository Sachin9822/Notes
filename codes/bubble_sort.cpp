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