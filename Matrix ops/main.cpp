#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<pair<int,int>,int> > ind;
bool mycomp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    return a.second<b.second;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n*n+1];
    int ans[n+1][n+1];
    int ex =0;
    for(int i=1;i<=n*n;i++)
    {
        cin>>a[i];
        ex+=a[i];
        a[i]=1;
    }
    ex-= n*n;
    int i = n*n;
    while(ex>0)
    {
        ex-=(m-1);
        a[i--]=m;
    }
    a[i]+=ex;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
            ind.push_back(make_pair(make_pair(i,j),i*j));
    }
    sort(ind.begin(),ind.end(),mycomp);
    for(int i =1;i<=n*n;i++)
    {
        //cout<<ind[i].second<<" ";
        ans[ind[i].first.first][ind[i].first.second] = a[i];
    }
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
