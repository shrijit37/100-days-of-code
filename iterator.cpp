#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


int main()
{

vector <int> v = {1,2,3,4,5,6};
//how to declare iterator


vector<int> :: iterator it = v.begin();
 
 for (it=v.begin();it!=v.end();++it)
 {
  cout<<*it<<endl;
 }


 //to run code : g++ -std=c++11 <filename>
 //then //  "./<filename>"


 //iterator are mainly used in case on non-contagious data structure  ex->tree,set,map



 //in case of map


// types of iterator 

// 1. const_iterator->this is a read only iterator means that it can only be used to read the value can cannot alter it 
// 2. iterator -> this can be used to read as well as alter the value 

 unordered_map<int , string> m;

 m[4]="srivastav";
 m[1]="shrijit";


 for(unordered_map<int ,string>::iterator it = m.begin();it !=m.end();it++)
 {
    cout<<it->first<<" "<< it->second<<endl;
 }

//or inshort 

for(auto [key,value] : m)
{
    cout<<key<<" "<<value<<endl;
}

}
