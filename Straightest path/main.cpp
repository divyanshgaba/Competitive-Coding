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
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const ll INF = 1e9;
const ll N = 1e3;
char grid[N][N];
ll walk[N][N];
ll n,m;
ll answer(ll i,ll j,ll dir)
{
    cout<<i<<" "<<j<<" "<<dir<<endl;
    if(i>=n || i<0 || j<0||j>=m || grid[i][j] == '*')
        return INF;
    if(grid[i][j] == 'H')
        return 0;
    if(walk[i][j] < INF)
        return walk[i][j];
    ll ans = INF;
    switch(dir)
    {
        case 0:
            ans = min(ans,answer(i,j+1,0));
            ans = min(ans,1+answer(i,j-1,1));
            ans = min(ans,1+answer(i+1,j,2));
            ans = min(ans,1+answer(i-1,j,3));
            break;
        case 1:
            ans = min(ans,1+answer(i,j+1,0));
            ans = min(ans,answer(i,j-1,1));
            ans = min(ans,1+answer(i+1,j,2));
            ans = min(ans,1+answer(i-1,j,3));
            break;
        case 2:
            ans = min(ans,1+answer(i,j+1,0));
            ans = min(ans,1+answer(i,j-1,1));
            ans = min(ans,answer(i+1,j,2));
            ans = min(ans,1+answer(i-1,j,3));
            break;
        case 3:
            ans = min(ans,1+answer(i,j+1,0));
            ans = min(ans,1+answer(i,j-1,1));
            ans = min(ans,1+answer(i+1,j,2));
            ans = min(ans,answer(i-1,j,3));
            break;
    }
    walk[i][j] = ans;
    return ans;


}


int main()
{
	fast;
	cin>>n>>m;
	pi V,H;
	for(ll i = 0;i<n;i++)
    {
        for(ll j = 0;j<m;j++)
        {
            walk[i][j] = INF;
            cin>>grid[i][j];
            if(grid[i][j] == 'V')
                V.F = i,V.S = j;
            else if (grid[i][j] == 'H')
                H.F = i, H.S = j;
        }
    }
    answer(V.F,V.S,0);
    if(walk[H.F][H.S] < 1e9)
        cout<<walk[H.F][H.S]<<endl;
    else
        cout<<-1<<endl;
	return 0;
}
