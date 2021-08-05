
/* 

linked list complete with it's formation and all operations on it 

refer video in case of doubt: https://www.youtube.com/watch?v=mDt53JLj8sM&t=455s

*/

// refer site : https://simplesnippets.tech/courses/data-structures-algorithms-course/

// if confused ...



#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next; 
    int key;

    node()
    {
        data=0;
        next =NULL;
        key=0;
    }
    node(int k,int d)
    {
        key=k;
        data=d;
    }

};

class singlylinkedlist
{   
    public:
    node *head;

    singlylinkedlist()
    {
        head=0;
    }

    singlylinkedlist(node *n)
    {
        head=n;

        
    }

    node *nodeexist(int k)              //funtion of data type node pointer
                                        //check if node exist using key values
    {
        node *temp= NULL;
        node *ptr = head;

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

    //inset node at the end

    void append(node *n)
    {
        if(nodeexist(n->key)!=NULL)
        {
            cout<<"Node Already exist"<<endl;
        }
        else
        {   
           if(head==NULL)                       //when the sll is empty
           {
               head=n;
               cout<<"Node Appended"<<endl;
           }
           else 
           {
               node * ptr = head;
               while (ptr->next!=NULL)              //traverse till 2nd last node 
                {
                    ptr=ptr->next;                  //ptr has address of last node.
                }
                ptr->next=n;
                cout<<"Node appended"<<endl;
              
           }
        }
    }

    //attaching node at the start 

    void prepend(node *n)
    {
        if(nodeexist(n->key)!=0)
        {
            cout<<"Node already exist"<<endl;
        }
        else 
        {
            n->next=head;
            head=n;
            cout<<"Node appended"<<endl;
        }
    }

    //insert node in b/w
    //this is why key value is required 

    void insert(int k,node *n)
    {
        node *ptr = nodeexist(k);                   //this will store the index of k in ptr

        if(ptr==NULL)
        {
            cout<<"No node exist with this key"<<endl;
        }
        else{
             if(nodeexist(n->key)!=0)
        {
            cout<<"Node already exist"<<endl;
        }
        else{

            n->next=ptr->next;
            ptr->next=n;
        }

        }
    }

    // Deleting value by key value 

    void delnode(int k)

    {
        node *ptr= nodeexist(k);
        if(head==NULL)  //to check if linked list is empty 
        {
            cout<<"Nothing to delete"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k)
            {
                head = head->next;
                cout<<"Node deleted"<<endl;
            }
        }
        else 
        {
            node *temp;
            node *prevptr=head;
            node *curptr= head->next;
            
            while(curptr!=NULL)
            {
                if(curptr->key==k)              //if condition checks that means this is the node to be deleted
                {
                    temp = curptr;   //storing the location of to be deleted node into temp
                    curptr=NULL;  //unlinking the node
                }

                else{
                    prevptr=prevptr->next;
                    curptr=curptr->next;
                }
            }

            if(temp!=NULL)
            {
                prevptr->next=curptr->next;
                cout<<"Node deleted;"<<endl;
            }

            else
            {
                cout<<"Node does not exist"<<endl;
            }

        }  
    }
    
    // updating data in node with key

    void update(int k,int d)
    {
        node *ptr = nodeexist(k);

        if(ptr!=NULL)
        {
            ptr->data=d;
            cout<<"Node updated successfully"<<endl;
        }
        else
        {
            cout<<"Node does not exists"<<endl;
        }
    }

    //printing of entire linked list

    void printall()
    {
        if(head==NULL)                                      //if linked list is empty
        {
            cout<<"NO nodes to print"<<endl;
        }
        
        else
        {
            node *temp = head;

            while(temp!=NULL)
            {
                cout<<temp->data<<" "<<endl;
                temp=temp->next;
            }
        }
    }


};


int main()
{
    singlylinkedlist s;
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
            s.insert(k1,n1);

            break;

            case 4:
            cout<<"Enter key of node to be deleted "<<endl;
            cin>>k1;

            s.delnode(k1);

            break;

            case 5:
            cout<<"Enter the key to be updated and to be updated  "<<endl;
            cin>>k1;
            cin>>data1;

            s.update(k1,data1);

            break;


            case 6:
            s.printall();

            break;

        }
    }
    while(option !=0);


    return 0;
}