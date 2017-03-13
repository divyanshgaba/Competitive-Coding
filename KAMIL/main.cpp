#include <iostream>
using namespace std;int main(){for(int i =0;i<10;i++){string s;cin>>s;int count =0;for(int i =0;s[i]!='\0';i++)if(s[i]=='D'||s[i]=='L'||s[i]=='T'||s[i]=='F')count++;cout<<count*count<<endl;}}
