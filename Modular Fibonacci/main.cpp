#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;


void multiply(ll F[2][2],ll M[2][2],ll m)
{
    ll temp[2][2];
    temp[0][0]= F[0][0]*M[0][0] + F[0][1]*M[1][0];
    temp[0][1]= F[0][0]*M[0][1] + F[0][1]*M[1][1];
    temp[1][0]= F[1][0]*M[0][0] + F[1][1]*M[1][0];
    temp[1][1]= F[1][0]*M[0][0] + F[1][1]*M[1][1];

    F[0][0] = temp[0][0]%m;
    F[0][1] = temp[0][1]%m;
    F[1][0] = temp[1][0]%m;
    F[1][1] = temp[1][1]%m;

}

void power(ll F[2][2],ll n,ll m)
{
    if(n<=1)
        return;
    ll M[2][2]={{1,1},{1,0}};
    power(F,n/2,m);
    multiply(F,F,m);
    if(n%2!=0)
    {
        multiply(F,M,m);
    }
}


ll result(ll n,ll m)
{
    ll F[2][2] = {{1,1},{1,0}};
    if(n <=1)
        return n%m;
    power(F,n-1,m);
    return F[0][0]%m;
}


int main()
{
	fast;
	ll n,m;
	while(cin>>n>>m)
    {
        m = round(pow(2,m));
        cout<<result(n,m)<<endl;
    }


	return 0;

}
