#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node * next;

    node(int val)
    {
      data = val;
      next=NULL;
    }
};

void add(int data,node* head)
{
    if(head==NULL)
    {
        node* ptr = new node(data);

        head = ptr;
        ptr->next=NULL;
    }

    else{
        node *temp= head;
        while(temp!=NULL)
        {
            temp=temp->next;
        }
        node *ptr=new node(data);
     

        ptr->next=NULL;
    }
}

void display(node* head)
{
    node* ptr = head;

    while(ptr!=NULL)    
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;

    }
}

int main()
{
    node* head = NULL;

    add(12,head);
    add(11,head);
    add(4,head);
    add(9,head);

    display(head);

    




}
