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

const int N = 5e3 +5;
int c[N];
vector<int> adj[N];
int n,q;



int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        cin>>n>>q;
        pre();
        for(int i =0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].PB(v);
            adj[v].PB(u);
        }
        for(int i = 0;i<n;i++)
            cin>>c[i];
        while(q--)
        {
            int s,b;
            cin>>s>>b;

        }
    }
	return 0;

}
