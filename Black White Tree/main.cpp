/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast  std::ios::sync_with_stdio(false)
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll n;
ll ans[123456][2];
vvi adj(123456);
ll param[123456][2];
set<int> asdas;

void gett(ll st,ll p,ll en)
{
    asdas.insert(st);
    for(auto it: adj[st])
    {
        if(it==p)
        continue;
        if(param[it][en]==1)
        gett(it,st,en);
    }
}

void dfs(ll x,ll p)
{
    for(auto it:adj[x])
    {
        if(it==p)
            continue;
        dfs(it,x);
        if(ans[it][0]>0)
        {
            ans[x][0]+=ans[it][0];
            param[it][0]=1;
        }
        if(ans[it][1]<0)
        {
            ans[x][1]+=ans[it][1];
            param[it][1]=1;
        }
    }
}

int main()
{
    fast;
    cin>>n;
    ll x,y;
    for(ll i=1;i<=n;i++)
    {
        cin>>x;
        ans[i][0]=(x==1)?1:-1;
        ans[i][1]=ans[i][0];
    }
    for(ll i = 1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,-1);
    ll final_ans=0;ll st=-1;ll en;
    for(ll i = 1;i<=n;i++)
    {
        if(abs(ans[i][0])>final_ans)
        {
            final_ans=max(final_ans,abs(ans[i][0]));
            st=i;en=0;
        }
        if(abs(ans[i][1])>final_ans)
        {
            final_ans=max(final_ans,abs(ans[i][1]));
            st=i;en=1;
        }
    }
    cout<<final_ans<<endl;
    gett(st,-1,en);
    cout<<asdas.size()<<endl;
    for(auto it:asdas)
        cout<<it<<" ";
    cout<<endl;
}
