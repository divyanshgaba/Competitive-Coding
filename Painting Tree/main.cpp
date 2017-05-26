#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

struct node
{
    ll h,c;
    int next,prev;
}g[100002];

ll h;
ll solve(int i,int j,bool dir)
{
    if(i==0 ||i == n+1)
        return 0;

}


int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        for(int i =1;i<=n;i++)
            cin>>g[i].h>>g[i].c;
        h = n-1;
        for(int i =1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].next = v;
            g[v].prev = u;
        }

    }
	return 0;

}
