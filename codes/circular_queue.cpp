#include <iostream>
#define N 5
using namespace std;
class queue{
int arr[N];
int front,rear;
public:
    queue(){
    front=-1;
    rear=-1;

    }
    void enqueue(int value){
    if(rear==-1&&front==-1){
    rear=0;
    front=0;
     arr[rear]=value;
    }
    else if(isfull()){
        cout<<"queue is full \n";
    } else{
    rear=(rear+1)%N;
    arr[rear]=value;
    }


    }
    bool isfull(){
    if(((rear+1)%N)==front)
        return true;
    else
        return false;


    }
    bool isempty(){
    if((rear==-1&&front==-1))
        return true;
        else
        return false;
    }
    void dequeue(){
    if(isempty()){
        cout<<"queue is empty \n";

    }else if(front==rear){
    cout<<"queue will be empty after this \n";
    rear=-1;
    front=-1;

    }else {

    cout<<arr[front]<<" dequeued \n";
    front=(front+1)%N;

    }


    }
    void display(){
    int i =front;
    if(isempty()){
       cout<<"queue is empty \n";
    }else


    while(i!=rear){
        cout<<arr[i]<<endl;
        i=(i+1)%N;

    }

    cout<<arr[rear];
    }
    void frontelement(){
    if(isempty()){
        cout<<"empty\n";

    }else
    cout<<arr[front]<<endl;


    }
    void rearelement(){
    if(isempty()){
        cout<<"empty\n";

    }else
    cout<<arr[rear]<<endl;


    }

    void sizeofqueue(){
    if(isempty()){
        cout<<"0 empty \n";
    } else
    cout<<rear-front+1<<endl;

    }



};

int main()
{
    queue q;
    int choice;
int x;

do{

    cout<<" press 1 to enqueue \n press 2 to dequque \n press 3 to display \n press 4 to view front element \n press 5 to view rear element \n press 6 to check the size \n press 0 to exit \n";
cin>>choice;
switch(choice)
{


case 1:
    {

        cout<<"give the number to be added \n";
        cin>>x;
        q.enqueue(x);
        break;
    }
case 2:
    {

        q.dequeue();
        break;
    }
case 3:
    {

        q.display();
        break;
    }
case 4:
    {
        q.frontelement();
        break;
    }
case 5:
    {
        q.rearelement();
        break;
    }
case 6:
    {
        q.sizeofqueue();
        break;
    }
case 0:
    {
        cout<<"you chose to exit \n";
        break;
    }
default:
    cout<<"invalid input";
}
}while(choice!=0);


    return 0;
}