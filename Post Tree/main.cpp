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

struct tree
{
    ll a;
    int next,supernext;
    bool is_super;
    int count;
}node[100001];

const ll INF = 1e9 +7;

int memo[100001];

int parents(int i)
{
   if(i == 0)
        return 1;
   if(node[i].count != 0)
   {
       return node[i].count;
   }
   node[i].count = 1 + pre(node[i].next);
   return node[i].count;
}
void pre(int n)
{
    for(int i =0;i<n;i++)
    {
        node[i].count = parents(i);
    }
}


ll answer(int i,ll best)
{
    if(i == 0)
    {
        return min(node[i].a,best);
    }
    best = min(best,node[i].a);
    ll ans = best + answer(node[i].next,best);
    return ans;
}



int main()
{
	fast;
	int n;
	cin>>n;
	int p[n];
	ll a[n];
	node[0].next = -1;
	for(int i =1;i<n;++i)
    {
        cin>>p[i];
        node[i].next = p[i]-1;
    }
	for(int i =0;i<n;++i)
    {
        cin>>a[i];
        node[i].a = a[i];
        node[i].is_super = false;
    }
    pre(n);
    for(int i =0;i<n;i++)
        cout<<answer(i,INF)<<" ";


	return 0;

}
