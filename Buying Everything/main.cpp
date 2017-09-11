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

int main()
{
	fast;
    int n,k,m;
    cin>>n>>m>>k;
    int a[n];
    int x = 0;
    int fi =0;
    vector<int> one;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        if(a[i] == 1)
            one.PB(i);
    }
    if(one.size()<m)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll best = 1e18;
    ll c = 0;
    vector<ll> diff(one.size(),0);
    ll prev = one.size()-1;
    for(int i = 1;i<one.size();i++)
    {
        cost[i] = one[i]-one[i-1];
    }
    vector<ll> exp(one.size(),0);
    for(int )
    {

    }
    for(int i = 0;i<one.size();i++)
    {
        if(i + m > one.size)
            break;
        ll ans = i +
    }



	return 0;

}
