#include<iostream>
#include<math.h>
using namespace std;

bool is_prime(int n)
{

    // if(n<=1)
    // {
    //     return false;
    // }   
    for(int i=2;i<=sqrt(n);i++)
    {
        cout<<"sime";
        if(n%i==0)
        {
            return false;
        }

    }
    return true;
}
int main()
{
   int x=3;
    int y=3;
    if(is_prime(4))
    {
        cout<<"prime";
    }
    
}