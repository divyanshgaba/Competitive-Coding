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

int n,m;
const ll INF = 1e9;
ll val;
int grid[3][50];


int answer(int i,int j)
{
    if(i == n || j == m)
    {
        if(set_all())
            return 0;
        return INF;
    }
    if(a[i][j] == 2)
        return INF;
    a[i][j] = 2;
    refresh();
    int temp = min(1+answer(i+1,j),1 + answer(i,j+1));
    a[i][j]=0;
    refresh();

    temp = min(temp,answer(i+1,j));
    temp = min(temp,answer(i,j+1));

    return temp;


}

int main()
{
	fast;
	ll test;
	cin>>test;
	while(test--)
    {
        memo.clear();
        a[0].reset(),a[1].reset(),a[2].reset();
        cin>>n>>m;
        if(n == 1)
            cout<<m<<endl;
        else
            cout<<answer(0,0)<<endl;
    }
	return 0;

}
