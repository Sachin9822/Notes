#include<iostream>
#define MAX 100
using namespace std;
class quick_sort{
	int arr[MAX];
	int x;
	public:
	int partition(int LowerB,int upperB){
		int pivot = arr[upperB];
		int i = LowerB - 1;	

		for(int j = LowerB;j<upperB;j++){
			if(arr[j]<pivot){
				i++;
				swap(arr[j],arr[i]);
			}
		}
		swap(arr[i+1],arr[upperB]);
		return upperB;
	}
	void sort(int start,int end){
		int p;
		if(start < end){
			p = partition(start,end); 
			sort(start,p-1);
			sort(p+1,end);
		}

	}
	void input_data(){
		cout<<"Enter the number of element: ";
		cin>>x;
		for(int i =0;i<x;i++)
			cin>>arr[i];
		sort(0,x-1);
	}
	int size(){
		return x;
	}
	void display(){
		for(int i = 0;i<x;i++){
			cout<<arr[i]<<" ";
		}
	}
};

int main(){
	quick_sort q;
	q.input_data();
	q.display();
	return 0;
}
