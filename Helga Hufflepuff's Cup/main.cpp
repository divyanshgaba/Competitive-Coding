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
const int m = 1e9 +7;
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];
	for(int i = 0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    int k,x;
    cin>>k>>x;

	return 0;

}
