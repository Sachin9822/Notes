#include<iostream>
#define MAX 100
using namespace std;
class quick_sort{
	int arr[MAX];
	int x;
	public:
	int partition(int LowerB,int upperB){
		int pivot = arr[LowerB],temp;
		int start = LowerB,end = upperB;
		while(start<end){
			while(arr[start]<=pivot)
				start++;
			while(arr[end]>pivot)
				end--;
			if(start<end){
				temp = arr[start];
				arr[start] = arr[end];
				arr[end]= temp;
			}
		}
		temp = arr[LowerB];
		arr[LowerB] = arr[end];
		arr[end] = temp;
		return end;
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
