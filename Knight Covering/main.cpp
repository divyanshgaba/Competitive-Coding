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


int solve(int n,int m)
{

}

int main()
{
	fast;
	ll test;
	cin>>test;
	while(test--)
    {
        cin>>n>>m;
        if(n == 1)
            cout<<m<<endl;
        else if(n == 2)
        {
            cout<< (m/6)*4 + min(m%6,2)*2<<endl;
        }
        else
        {
            cout<<solve(n,m)<<endl;
        }
    }
	return 0;

}
