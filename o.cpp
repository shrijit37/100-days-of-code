
    #include<iostream>
    using namespace std;

    #define ll long long
    #define ull unsigned long long

    #define pb push_back


    int main()

    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        ll t;
        cin>>t;
        while(t--)
        {
            string s;
            cin>>s;
            ll n=s.size();
            ll maxx=0,minn=0;
            ll idx=0;
            ll sign=1;
            while(idx<n)
            {
                if(s[idx]=='?')
                {
                    if(sign==1)maxx++;
                    else minn++;
                }
                else if(s[idx]=='+')
                {
                    sign=1;
                }
                else if(s[idx]=='-')
                {
                    sign=0;
                }
                else if(s[idx]=='(')
                {
                    ll arr[3];
                    arr=do(idx,s);
                    if(sign==1)
                    {
                        maxx+=arr[0];
                        minn+=arr[1];
                    }
                    else
                    {
                        maxx+=arr[1];
                        minn+=arr[0];
                    }
                    idx=arr[2];
                }
                idx++;
            }
            cout<<maxx<<" "<<minn<<"\n";
        }
        return 0;
    }

    correct the above code

    #include<iostream>
    using namespace std;

    #define ll long long
    #define ull unsigned long long

    #define pb push_back

    int main()

    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        ll t;

        cin>>t;

        while(t--)
        {
            string s;
            cin>>s;
            ll n=s.size();
            ll maxx=0,minn=0;
            ll idx=0;
            ll sign=1;
            while(idx<n)
            {
                if(s[idx]=='?')
                {
                    if(sign==1)maxx++;
                    else minn++;
                }
                else if(s[idx]=='+')
                {
                    sign=1;
                }
                else if(s[idx]=='-')
                {
                    sign=0;
                }
                else if(s[idx]=='(')
                {
                    ll arr[3];
                    arr=do(idx,s);  
                    if(sign==1)
                    {
                        maxx+=arr[0];
                        minn+=arr[1];
                    }
                    else
                    {
                        maxx+=arr[1];
                        minn+=arr[0];
                    }
                    idx=arr[2];
                }
                idx++;
            }
            cout<<maxx<<" "<<minn<<"\n";
        }