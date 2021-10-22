#include<iostream>
#include<math.h>
using namespace std;

bool is_prime(int n)
{   
    for(int i=2;i<=sqrt(n);i++)
    {
        
        if(n%i==0)
        {
            return false;
        }

    }
    return true;
}

int main()
{
    int x,y;
    int t;
    scanf("%d",&t);
    int step;

    while(t--)

    {

        scanf("%d %d",&x,&y);
        step =0;
     while(x!=(y))
        {
            if(is_prime(x+2)&&(x+2)<=y)
            {
                step++;
                x=x+2;
               
            }
            else if((x+2)<=y)
            {
                step++;
                x++;
              
            }
            else 
            {
                step++;
                break;
            }
        }

        printf("%d\n",step);
    }
 
}