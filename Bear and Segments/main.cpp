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
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll n,p;
        cin>>n>>p;
        int a[n];
        ll sum[n];
        memset(sum,0,sizeof(sum));
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            if(i ==0)
                sum[i]=a[i];
            else
            {
                sum[i]= sum[i-1] +a[i];
            }
        }
        ll ele=-1,cnt=0;

        for(int i =0;i<n;i++)
        {
            if(ele < sum[i]%p)
            {
                ele =sum[i]%p;
                cnt=1;
            }
            else if(ele == sum[i]%p)
            {
                cnt++;
            }
            for(int j =0;j<i;j++)
            {
                ll t = (sum[i] - sum[j])%p;
                if(ele < t)
                {
                    ele = t;
                    cnt=1;
                }
                else if(ele == t)
                {
                    cnt++;
                }
            }
        }
        cout<<ele<<" "<<cnt<<endl;


    }
	return 0;

}
