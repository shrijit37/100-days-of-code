#include<iostream>
#include<string>
using namespace std;


int main()
{
  int t;
  cin>>t;

  int left ,right;
  left=right=0;
  
  bool is_print=false;
  while(t--)
  {
    int n;
    cin>>n;
    string str;
    cin>>str;
    bool is_print=false;

    for(int i=0;i<n-1;i++)
    {
      if(str[i]=='L'&&str[i+1]=='L')
      {
        cout<<"YES"<<endl;
        is_print=true;
        break;
      }
    else if(str[i]=='R'&&str[i+1]=='R')
      {
        cout<<"YES"<<endl;
      is_print=true;
        break;
      }


    }

    if(!is_print)

    {

    cout<<"NO"<<endl;
    }

  }
}