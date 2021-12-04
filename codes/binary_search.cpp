#include<iostream>

using namespace std;

class Binary_search{
	int size;
	int arr[100];
	public:
	void input_data(){
		cout<<"Enter the size of the data: ";
		cin>>size;
		for(int i = 0;i<size;i++){
			cin>>arr[i];
		}
	}
	void search(){
		int data;
		cout<<"Enter the data to search: ";
		cin>>data;
		int mid,end=size-1,start=0;
		while(end>=start){
			mid = (start+end)/2;
			if(arr[mid] == data){
				cout<<"Item Found\n";
				return;
			}
			else if(data < arr[mid]){
				end = mid - 1;
			}
			else 
				start = mid + 1;
		}
		cout<<"Not found\n";
	}

};

int main(){
	Binary_search b;
	b.input_data();
	for(int i = 0;i<5;i++)
		b.search();
	return 0;
}

