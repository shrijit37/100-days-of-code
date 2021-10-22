#include<iostream>
#include<math.h>
using namespace std;

bool is_prime(int n)
{
    if(n<2)
    {
        return true;
    }
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int hcf(int a,int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}


int main()
{
    int t;
    cin>>t;
    int x,k;
    int max;
    int min;
    while(t--)
    {
        min=0;
        max=0;
        cin>>x>>k;
        for(int i=(x*k)-1;i>0;i--)
        {
            for(int j=i+1;j>0;j--)
            {
                if(is_prime(i)&&is_prime(j))
                {
                    max=(i*j)/hcf(i,j);
                }
            }
        }

        for(int i=0;i<(x*k);i++)
        {
            for(int j=i+1;j<(x*k);j++)
            {
                if(is_prime(i)&&is_prime(j))
                {
                    min=(i*j)/hcf(i,j);
                }
            }
        }
        cout<<min<<" "<<max<<endl;

    }
}