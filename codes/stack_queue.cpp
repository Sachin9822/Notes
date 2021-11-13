#include<iostream>
#define max 5
using namespace std;

class queues
{
    int queue[max];
    int rear, front;

public:

    queues()
    {
        front=-1;
        rear=-1;
    }
     bool isfull();
     bool isempty();
     void push(int data);
     void peek();
     void display();
     void pop();
};


bool queues::isfull()
{
    if(rear==max-1)
        return true;

    else
        return false;
}

bool queues::isempty()
{
    if(front==-1||front>rear)
        return true;

    else
        return false;
}

void queues::push(int data)
{
    if(isfull())
    {
        cout<<"\n\n**QUEUE IS FULL**\n";
    }
    else
    {
        if(rear==-1&&front==-1)
        {
            rear++;
            front++;
            queue[rear]=data;
        }
        else
        {
            rear++;
            queue[rear]=data;
        }
    }
}

void queues::peek()
{
    if(isempty())
    {
        cout<<"\n\n**QUEUE IS EMPTY**\n";
    }

    else
    {
        cout<<"\nThe peeked value is: "<<queue[front];
    }
}

void queues::display()
{
    if(isempty())
    {
        cout<<"\n\n**QUEUE IS EMPTY**\n";
    }
    else
    {
        cout<<"\nThe Queue:\n";
        for(int i=rear;i>=front;i--)
        {
            cout<<queue[i]<<endl;
        }
    }
}

void queues::pop()
{
    if(isempty())
    {
        cout<<"\n\n**QUEUE IS EMPTY**\n";
    }
    else
    {
        cout<<"\nThe Popped value is: "<<queue[front];
        front++;
    }
}

int main()
{
    queues qs;

    int choice, input, num;

    do
    {
        cout<<"\nPress 1 to Push";
        cout<<"\nPress 2 to Peek";
        cout<<"\nPress 3 to Display";
        cout<<"\nPress 4 to Pop";
        cout<<"\nMake a choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\nEnter the data to be pushed: ";
            cin>>num;
            qs.push(num);
            break;

        case 2:
            qs.peek();
            break;

        case 3:
            qs.display();
            break;

        case 4:
            qs.pop();
            break;

        default:
            cout<<"\n\n**Invalid Input**\n";
            break;
        }

        cout<<"\nPress 1 to Continue";
        cout<<"\nPress 0 to Exit";
        cout<<"\nEnter an Input: ";
        cin>>input;

        cout<<endl;

    }while(input!=0);

    return 0;
}