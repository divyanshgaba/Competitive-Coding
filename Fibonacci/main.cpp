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

vector<int> fib;

void init()
{
    fib.PB(0),fib.PB(1);
    for(int i = 2;i<60;i++)
    {
        fib.PB((fib[i-1]+fib[i-2])%10);
    }

}
int main()
{
	fast;
	init();
	ll test=1;
	cin>>test;
	while(test--)
    {
		ll n;
		cin>>n;
		n = (n+1)%60;
		cout<<fib[n]<<endl;
    }
	return 0;

}
