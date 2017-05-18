#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	ll n,ans;
	cin>>n;
	ll temp = n;
    ans = n;
    ll i =0;
    while(n/10 != 0)
    {
        ll t = n%10;
        if(t!=0)
        n+=(10-t),ans+=round(pow(10,i))*(10-t);
        n/=10,++i;
    }
    if(ans == temp)
        ans+=round(pow(10,i));
    cout<<ans-temp<<endl;
	return 0;

}
