#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;  
    cin>>t; 
    int x,k;
    int min,max;
    
    int lcm;
    
    while(t--)
    {
        max=0;
        min=1000000000;
        
        scanf("%d %d",&x,&k);

        for(int i=x;i<(x*k);i++)
        {
            for(int j=i+1;j<=(x*k);j++)
            {
                    lcm=(i*j)/(__gcd(i,j));
                     
                    if(lcm>max)
                    {
                        max=lcm;
                    }
                    if(i==(x*k)/8)
                     {
                        i=((x*k)*3)/4;
                     }
                     if(lcm<min)
                    {
                        min=lcm;
                    }
                
            }
        }
    printf("%d %d\n",min,max);


    }
}