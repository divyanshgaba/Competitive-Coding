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
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i = 0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int cov = 0;
	int ans = 0;
    for(int i = 0;i<n-1;i++)
    {
        if(a[i] <= cov)
            continue;
        for(int j = i+1;j<n;j++)
        {
            if(a[j]-a[i] > k)
            {
                cov = a[j-1]+k;
                ans+=1;
                break;
            }
        }
    }
    if(cov < a[n-1])
        ans+=1;
    cout<<ans<<endl;

    return 0;
}
