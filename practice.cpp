#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cin>>n;

    int p;
    cin>>p;

    int t;
    vector<int> v;
    vector <int> ans;
    for(int i=0;i<n;i++)
    {   
        cin>>t;

        v.push_back(t); 

    }
    int max;
    int i=0; int k=p;
    while(k<=v.size())
    {

        max=0;
        for(int l=i;l<k;l++)
        {
           if(v[l]>max)
           {
               max=v[l];
           }
        }
        ans.push_back(max);
        i++;
        k++;
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
