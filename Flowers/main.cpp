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
ll n[100001];
const ll mod = 1e9 +7;
ll sum[100001];
void precomp(int k)
{
    for(int i =1;i<=100000;++i)
    {
        if(i<k)
            n[i]=1;
        else
            n[i] = n[i-1] + n[i-k];
        if(n[i]>mod)
            n[i]%=mod;
    }
    sum[1]=n[1];
    for(int i =2;i<=100000;++i)
        sum[i]=(sum[i-1]+n[i])%mod;
}

int main()
{
	fast;
	int t,k;
	cin>>t>>k;
	precomp(k);
	while(t--)
    {
        int a,b;
        cin>>a>>b;
        int ans = sum[b]-sum[a-1];
        if(ans<0)
            ans+=mod;
        cout<<ans<<endl;
    }
	return 0;

}
