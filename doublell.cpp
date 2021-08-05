#include<iostream>
using namespace std;

class node
{   
    public:
    int data;
    int key;
    node *next;
    node *prev;

    node()
    {
        data=0;
        key=0;
        next=NULL;
        prev=NULL;
    }

    node(int k,int dat)
    {
        key=k;
        data=dat;
    }
};

class dll
{   
    public:
    node *head;             //pointer to node class

    dll()
    {
        head=NULL;
    }

    dll(node *n)
    {
        head=n;
    }

    //check if node exist

node *checkNode(int k)              //node pointer is used because if node exist it will return pointer to it 
    {
        node *temp = NULL;
        node *ptr= head;

        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
            ptr=ptr->next;
        }

        return temp; 
    }

    //append node at end 

void append(node *n)

{
   if(checkNode(n->key)!=NULL)
   {
       cout<<"Node already exist with key value"<< n->key<<endl;
   }

   else
   {
       //else has two condition 
       //1. if head is null ie. linked list is empty
        //2. head is not null
       if(head==NULL)
       {
        head=n;
        cout<<"Node appended"<<endl;
       }
       else
       {    
           node *ptr =head;
           while(ptr!=NULL)
           {
               ptr=ptr->next;               //iterating till end 
           }
           ptr->next=n;
           n->prev = ptr;
           cout<<"node appended"<<endl;

       }
   }
}

     //prepend node 

void prepend(node *n)
{
    
    if(checkNode(n->key)!=NULL)
    {
        cout<<"Node already exits"<<endl;
    }
    else 
    {
        if(head==NULL)
        {
            head=n;
            cout<<"Node prepend successfully "<<endl;
        }

        else
        {
        head->prev=n;
        n->next=head;
        head=n;
        cout<<"Node prepended"<<endl;
        }
    }
}

    //inserting node in b/w

    // check with key k already exist or not 
        //if not exit the process 
        //else continue the process
    //check if key(to be added) already exist 
    //if rare key :
        //check if its the last node
        //if list empty then add to the head
        //do the insertion process according to condition
        

        // !!!!dont forget backlinking !!!!

void insertbtw(int k, node *n)
{
    node *ptr = checkNode(k);

    //ptr will store the value after which the node will be added

    if(ptr==NULL)
    {
        cout<<"Key doesn't exist "<<endl;
    }

    else{   
        if(checkNode(n->key)!=NULL)
        {
            cout<<"Key to be added already exists "<<endl;
        }

        else
        {
            node *nxtnode = ptr->next; 
            //nxtnode pointer will store the value of "next" in k node 

            if(nxtnode==NULL)
            {
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node added "<<endl;
            }
            else 
            {
                n->next = nxtnode;
                nxtnode->prev=n;
                n->prev=ptr;
                ptr->next=n;

                cout<<"Node added successfully"<<endl;
            }

         }

    }
    
}


    //deletion of node 




    void deletebykey(int k)
    {
        node *ptr = checkNode(k);               //store the location of tobe deleted node in ptr 

        if(ptr==NULL)
        {
            cout<<"Node does not exist"<<endl;
        }

        //store the location of prev and next node 
        else
        {
            node *nextnode = ptr->next;
            node *prevnode = ptr->prev;
            //deletion of last node 
            if(nextnode==NULL)
            {
                prevnode->next=NULL;
                cout<<"Node deleted"<<endl;
            }
            //deletion in b/w node 
            else
            {
                prevnode->next=nextnode;
                nextnode->prev=prevnode;
                cout<<"Node deleted in b/w"<<endl;
            }
        }

    }


    //update node 

    void updatenode(int k, int d)
    {
        node* ptr= checkNode(k);

        if(ptr==NULL)
        {
            cout<<"Node does not exist"<<endl;
        }
        else
        {
            ptr->data=d;
            cout<<"Node updated "<<endl;
        }
    }

    //print complete list 

    void printlist()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {   
            node* ptr = head;
            while(ptr->next!=NULL)
            {
                cout<<ptr->data;
                ptr=ptr->next;
            }
        }
    }
};




int main()
{

    dll s;
    int option; 
    //menu driven program 

    int key1, k1 , data1;

    do
    {
        cout<<"What operation do you want to preform .. .. . . .enter 0 to exit"<<endl;
        cout<<"1. To append node "<<endl;
        cout<<"2. To prepend node "<<endl;
        cout<<"3. To insert node in b/w"<<endl;
        cout<<"4. Delete node by key "<<endl;
        cout<<"5. Update node by key"<<endl;
        cout<<"6. Print all nodes/ complete linked list "<<endl;
        cout<<"7. Clear screen"<<endl<<endl<<endl;

        cin>>option;
        node *n1 = new node();              //object of node is created in heap which can be accessed with n1 pointer

        switch(option) 
        {
            case 0: 
           
            break;

            case 1: 
            cout<<"Enter key and data of node to be appened "<<endl;
            cin>>key1>>data1;
            n1->key=key1;
            n1->data=data1;
            s.append(n1);

            break;

            case 2:
            cout<<"Enter key and data of node to be prepened "<<endl;
            cin>>key1>>data1;
            n1->key=key1;
            n1->data=data1;
            s.prepend(n1);

            break;

            case 3:
            cout<<"Enter the key after which you want to add the new node "<<endl;
            cin>>k1;    
            cin>>key1>>data1;
            n1->key=key1;
            n1->data=data1;
            s.insertbtw(k1,n1);

            break;

            case 4:
            cout<<"Enter key of node to be deleted "<<endl;
            cin>>k1;

            s.deletebykey(k1);

            break;

            case 5:
            cout<<"Enter the key to be updated and to be updated  "<<endl;
            cin>>k1;
            cin>>data1;

            s.updatenode(k1,data1);

            break;

            case 6:
            s.printlist();

            break;

            case 7:
             system("clear");
            break;

        }
    }
    while(option !=0);


    return 0;
}