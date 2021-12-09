#include <iostream>
using namespace std;
void merge(int arr[],int l, int m,int r,int size){
	int i=l;
	int j=m+1;
	int k=l;
	int temp[size];
	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= m) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	for (int p = l; p <= r; p++) {
		arr[p] = temp[p];
	}
}
void mergesort(int arr[],int l,int r,int size){
	if(l<r){
		int m=(l+r)/2;
		mergesort(arr,l,m,size);
		mergesort(arr,m+1,r,size);
		merge(arr,l,m,r,size);
	}
}
int main()
{
	int size;
	cout<<"enter size \n";
	cin>>size;
	int array[size];
	cout<<"enter the data \n";
	for(int i=0;i<size;i++){
		cin>>array[i];
	}
	cout<<endl;
	cout<<"before sorting \n";
	for(int i=0;i<size;i++){
		cout<<array[i]<<"  ";
	}
	cout<<endl;
	mergesort(array,0,size-1,size);
	cout<<"after sorting \n";
	for(int i=0;i<size;i++){
		cout<<array[i]<<"  ";
	}
	return 0;
}
