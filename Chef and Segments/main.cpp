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


ll n;
ll a[100001];
array<array<ll,25>,100001> fac;
array<array<ll,25>,101> templates;
ll primes[26]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void build()
{
    for(int i =1;i<=100;i++)
    {
        int temp = i;
        for(int j =0;j<25&&temp;j++)
        {
            int cnt =0;
            while(temp%primes[j] ==0)
            {
                cnt++;
                temp/=primes[j];
            }
            templates[i][j]=cnt;
        }
    }
}

ll ans(ll b,ll ex,ll m)
{
    ll res =1;
    while(ex>0)
    {
        if(ex&1) res=(res*b)%m;
        b=(b*b)%m;
        ex>>=1;
    }
    return res%m;
}

ll freq[100002][26];

int main()
{
	fast;
	cin>>n;
	build();
    for(int i =0;i<n;i++) cin>>a[i],fac[i] = templates[a[i]];
    for(int i =1;i<=n;i++)
    {
        for(int j =0;j<25;j++)
        {
            freq[i][j] = freq[i-1][j] + fac[i-1][j];
            //cout<<freq[i][j]<<" ";
        }
        //cout<<endl;
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll l,r,m;
        cin>>l>>r>>m;
        ll res =1;
        for(int i =0;i<25;i++)
        {
            ll po = freq[r][i] - freq[l-1][i];
            res *=ans(primes[i],po,m)%m;
        }
        cout<<res%m<<endl;
    }
	return 0;

}
