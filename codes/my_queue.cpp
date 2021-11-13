#include<iostream>

using namespace std;

#define MAX 50

class queue{
	int arr[MAX],front,rear;
public:
	queue(){
		front = rear = -1;
	}
	bool is_empty(){
		if(rear < front || front == rear == -1){
			return true;
		}
		else
			return false;
	}
	bool is_full(){
		if(rear == MAX -1){
			return true;
		}
		else
			return false;
	}
	void Front(){
		if(!is_empty())
			cout<<arr[front]<<endl;
		else
			cout<<"\n-------Empty---------\n";
	}
	void Rear(){
		if(!is_empty())
			cout<<arr[rear]<<endl;
		else
			cout<<"\n--------Empty---------\n";
	}
	void dequeue(){
		if(!is_empty()){
			front++;
		}
		else
			cout<<"\n--------Empty---------\n";
	}
	void enqueue(int data){
		// if(front == rear == -1){
		// 	front++;
		// 	rear++;
		// 	arr[rear] = data;
		// }
		// else if(!is_full()){
		// 	arr[++rear] = data; 
		// }
		// else{
		// 	cout<<"\n-----------queue is full ----------\n";
		// }
		if(front == rear == -1){
			front = (front+1)%MAX;
			rear = (rear+1)%MAX;
			arr[rear] = data;
		}
		else if(!is_full()){
			arr[++rear] = data; 
		}
		else{
			cout<<"\n-----------queue is full ----------\n";
		}
	}
	void display(){
		cout<<"\n\n-----------Queue----------------\n";
		if(!is_empty()){
			for(int i = front+1;i<=rear;i++){
				cout<<arr[i]<<" ";
			}	
		}
		else
			cout<<"empty\n";
		cout<<"\n---------------------------------\n";
	}
};


int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.display();
	q.dequeue();
	q.display();q.dequeue();
	q.display();q.dequeue();
	q.Front();
	q.Rear();
	q.display();q.dequeue();
	q.display();q.dequeue();
	return 0;
}