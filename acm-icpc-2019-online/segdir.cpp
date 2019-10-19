//Author-ANKIT KUMAR MISHRA
//MNNIT Allahabad
//Problem Code- SEGDIR

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;

    while(t--)
    {
        vector <pair <pair<int,int> ,int> >pr;
        map <int,vector< pair<int,int> > >mp;
        cin>>n;
        int a,b,val;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>val;
            mp[val].push_back({a,b});
        }
        int flag=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int v=(*it).first;
            vector <pair<int,int> > seg=(*it).second;
            map <int,int> mp1;
            for(int i=0;i<seg.size();i++)
            {
                mp1[seg[i].first]++;
                mp1[seg[i].second+1]--;
            }int cnt=0;
            for(auto itr=mp1.begin();itr!=mp1.end();itr++)
            {
                cnt+=(*itr).second;
                if(cnt>=3)
                flag=1;
            }
        }
        if(flag)
        cout<<"NO"<<endl;
        else 
        cout<<"YES"<<endl;
    }
}
