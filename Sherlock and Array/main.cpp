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
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		bool ans = false;
		ll a[n+1],sum[n+1]={0};
		for(int i = 1;i<=n;i++) cin>>a[i];
		for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+a[i];
		for(int i = 1;i<=n;i++)
        {
            if(sum[i-1] == sum[n] - sum[i])
            {
                ans = true;
                break;
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
