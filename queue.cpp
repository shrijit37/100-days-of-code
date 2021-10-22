#include<iostream>
using namespace std;

// queue is linear data structure which operates on lilo and fifo
// i.e-last in last out and first in first out

//operation:-
//1. enque 
//2. deque

//elemnets are added from one end and elements are removed from other end 

//elements are added from rear end and removed from front end 

//queues can also be implemented with linked list or vector

//application - cpu scheduling , call centers

//implementaion of queue
class Queue
{   
    private:
        int front;
        int rear;
        int arr[5];

    public:

    Queue()
    {
        front=-1;
        rear=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }

    bool isempty()
    {
        if(front==-1&&rear==-1)
        {
            return true;
        }

        else{
            return false;
        }
    }

    bool isfull()
    {
        if(rear == size(arr)-1)
        {
            return true;
        }

        else{
            return false;
        }
    }
    
    void enqueue(int val)   
    {
        if(isfull)
        {
            cout<<"queue is full"<<endl;
        }
        else if(isempty)
        {
            front =0;
            rear =0;

            arr[front]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    int dequeue()
    {
        int x;
        if(isempty())
        {
            cout<<"queue is already enmpy"<<endl;
            return 0;
        }

        else if(front==rear)                    //first value has to removed 
        {
            x=arr[front];
            front =-1;
            rear=-1;
            arr[front]=0;
            return x; 
        }

        else                //we are removing element fron the front because in queue elements are removed from the front
        {
           x=arr[front];
           arr[front]=0;
           front++;
           return x; 
        }

    }

    int count()
    {   

        return((rear-front)+1);
    }

    void displayall()
    {
        for(int i=0;i<5;i++)
        {
            cout<<arr[i]<<" ";
        }
    }



};
//implement furthur using switch case 

int main()
{
    
}