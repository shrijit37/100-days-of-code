#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    int key;
};

class cll
{
    public:
    node *head;

    cll()
    {
        head=NULL;
    }

    node *exist(int k)
    {
        node *temp=NULL;
        node *ptr= head;

        if(ptr==NULL)
        {
            return temp;
        }
        else
        {
        do
        {
            if(ptr->key==k)
            {
                return ptr;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        }
        return temp;
    }

    //to append node 

    void append(int k,int d)
    {
        
    }
};

int main()
{
    return 0;
}