#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int N=2e5+10;
set<int> check[2];
bool vis[N];
vector<int> ans[N];

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]=='1')
            check[1].insert(i);
        else
            check[0].insert(i);
    }
    bool poss = true;
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            if(s[i]=='1')
            {
                poss = false;
                break;
            }
            bool t = false;
            int st = i;
            set<int>::iterator it;
            while((it=check[t].lower_bound(st))!=check[t].end())
            {
                ans[cnt].push_back(*it);
                vis[*it]=true;
                st = *it;
                check[t].erase(it);
                t=!t;
                //cout<<*it<<endl;
            }
            if(!t)
            {
                vis[ans[cnt][ans[cnt].size()-1]]=false;
                check[!t].insert(ans[cnt][ans[cnt].size()-1]);
                ans[cnt].pop_back();
            }
            cnt++;
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
            poss = false;
    }
    if(!poss)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<cnt<<endl;
    for(int i = 0;i<cnt;i++)
    {
        cout<<ans[i].size()<<" ";
        for(auto j:ans[i])
            cout<<j+1<<" ";
        cout<<endl;

    }
    return 0;
}
