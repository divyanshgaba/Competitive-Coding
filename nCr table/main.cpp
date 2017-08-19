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

const ll mod = 1e9;
ll table[1001][1001];

ll nCr(ll n,ll r)
{
    if(n == r || r == 0)
        return 1;
    if(table[n][r])
        return table[n][r];
    return table[n][r] = (nCr(n-1,r-1) + nCr(n-1,r))%mod;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		for(int i = 0;i<=n;i++)
        {
            cout<<nCr(n,i)<<" ";
        }
        cout<<endl;
    }
	return 0;

}
