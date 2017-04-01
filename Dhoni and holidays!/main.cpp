#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,a,b) for (int i = a; i < b;  i++)
#define MAX 1e9
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll arr[1001];
ll n;
ll mem[1001][2][2];
ll ans(ll i, ll a, ll d)
{
    if(i==n)
        return 0;
    if(a==1&&arr[i]%2==0)
        return MAX;
    if(d==1&&arr[i]<=1)
        return MAX;
    if(mem[i][a][d]!=0)
        return mem[i][a][d];
    ll temp=0;
    if(a==0&&d==0)
    {
        temp = min(ans(i+1,1,0),min(1+ans(i+1,0,0),ans(i+1,0,1)));
    }
    else
    {
        if(a==1 && d ==0)
        {
            temp = min(ans(i+1,0,1),1+ans(i+1,0,0));
        }
        else
        {
            temp = min(ans(i+1,1,0),1+ans(i+1,0,0));
        }
    }
    mem[i][a][d]=temp;
    return temp;


}

int main()
{
	fast;
	cin>>n;
	FOR(i,0,n)
        cin>>arr[i];
    cout<<min(1+ans(0,0,0),min(ans(0,1,0),ans(0,0,1)));
	return 0;

}
