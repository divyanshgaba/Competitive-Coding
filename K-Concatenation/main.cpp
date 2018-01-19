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
		int n,k;
		cin>>n>>k;
		ll a[n],b[n],c[n];
        ll sum = 0;
		for(int i = 0;i<n;i++)
            cin>>a[i],sum+=a[i];
        ll mid = a[0],temp = a[0];
        b[0]=a[0],c[n-1] = a[n-1];
        for(int i = 1;i<n;i++)
        {
            temp = max(a[i],temp+a[i]);
            mid = max(mid,temp);
            b[i] = b[i-1] + a[i];
            c[n-i-1] = c[n-i] + a[n-i-1];
        }
        ll ans = mid;
        for(int i = 0;i<n;i++)
        {
            temp = max(a[i],temp+a[i]);
            mid = max(mid,temp);
        }
        if(k>=2)
            ans = max(max(ans,mid),*max_element(b,b+n)+*max_element(c,c+n)+(k-2)*sum);
        cout<<ans<<endl;


    }
	return 0;

}
