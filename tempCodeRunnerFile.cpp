#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {   
        int i,e,d;
        
         i=0;
            e=0;    
            d=0;
        int inp;

        for(int k=0;k<5;k++)
        {  
            cin>>inp;
            if(inp==0)
            {
                d++;
            }
            else if(inp==1)
            {
                i++;
            }

            else if(inp==2)
            {
                e++;
            }
        }
        //india wins 
        if((i>e)&&(i>=d))
        {
            cout<<"INDIA"<<endl;
        }

        //england wins
        else if((e>=d)&&(e>i))
        {
            cout<<"ENGLAND"<<endl;
        }

        //draw

        else if((d>e and d>i) or e==i)
        {
            cout<<"DRAW"<<endl;
        }
        
    }


}