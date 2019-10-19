//Author-Ankit Kumar Mishra
//MNNIT Allahabad
//Problem code - TRAINSET

#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   map <string,int> tr;
   map <string,int> tot;
   while(t--)
   {
       int n;
       cin>>n;
       tr.clear();
       tot.clear();
       string str;int val;
       for(int i=0;i<n;i++)
       {
           cin>>str>>val;
           tot[str]++;
           if(val)
           tr[str]++;
       }
       int sum=0;
       for(auto it=tot.begin();it!=tot.end();it++)
       {
           int t=tr[(*it).first];
           int to=(*it).second;
           sum+=(max(t,to-t));
       }
       cout<<sum<<endl;
   }
}
