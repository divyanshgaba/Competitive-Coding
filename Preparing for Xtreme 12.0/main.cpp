/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int B = 111;
ll arr[B];
vector<string> v[B];
ll c = -1;
const ll INF = 1e15;
unordered_map<ll,ll> dp[B];
set<string> top;
ll p;
map<string,ll> m;
ll ans(int i,ll mask)
{
    if(mask==p)
        return 0;
    if(i==c)
    {
        return INF;
    }
    if(dp[i].count(mask)>0)
        return dp[i][mask];
    ll temp = 0;
    ll t = INF;
    t = min(t,ans(i+1,mask));
    for(auto j:v[i])
        temp = temp|(1<<m[j]);
    return dp[i][mask] = min(t,arr[i]+ans(i+1,mask|temp));
}

int main()
{
	fast;
	string s;
	while(getline(cin,s))
    {
        c++;
        string buf;
        stringstream ss(s);
        ss>>arr[c];
        while(ss>>buf)
            top.insert(buf),v[c].PB(buf);
    }
    c++;
    /*for(auto i:top)
        cout<<i<<" ";
    cout<<endl;*/
    {
        int k = 0;
        for(auto i:top)
        {
            m[i]=k++;
        }
    }
    //cout<<top.size()<<endl;
    p = (1<<top.size())-1;
    //cout<<c<<" "<<p<<endl;
    cout<<ans(0,0)<<endl;
    /*for(int i = 0;i<c;i++)
    {
        cout<<arr[i]<<" ";
        for(auto j:v[i])
            cout<<j<<" ";
        cout<<endl;
    }*/
	return 0;

}
