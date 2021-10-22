#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

//map is used to store <key> <value> pair 

//unordered = cam store values in unsorted manner
//ordered map= key has to be in sorted manner

//map are kind of data structure that have both key and value and both are in pairs



int main()
{
    map<int,string> m;

    // how to inser value

    m[1]="shrijit";
    m[2]="srivastav";

    //how to print iterator 

    map<int,string> :: iterator it;

    //m.begin() - point to first value of map

    //to print the values 

    // for(it=m.begin();it!=m.end();it++)
    // {
    //     cout<<(*it).first<<" "<<(*it).second<<endl; 
    // }

    // in short 

    for(auto &pr : m)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }

    //use cppreference for more funtions 
}