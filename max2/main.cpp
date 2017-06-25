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
	//fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll n;
        cin>>n;
        list<ll> freq[n];
        ll c[n],w[n];
        ll sum[n],pre[n];
        for(ll i = 0;i<n;i++)
            cin>>c[i],freq[c[i]].PB(i);
        for(ll i = 0;i<n;i++)
            cin>>w[i];
        sum[0]=w[0];
        for(ll i = 1;i<n;i++)
            sum[i] = sum[i-1] +  w[i];
        ll l=0,r = n-1;
        for(ll i = 0;i<=r;i++)
        {
            while(!freq[c[i]].empty() && freq[c[i]].front() < i)
            {
                freq[c[i]].pop_front();
            }
            while(!freq[c[i]].empty() && freq[c[i]].back() >r)
            {
                freq[c[i]].pop_back();
            }
            if(freq[c[i]].size() > 1)
            {
                ll x = freq[c[i]].front();
                ll y = freq[c[i]].back();
                ll left = sum[y-1];
                if(l)
                    left -= sum[l-1];
                ll right = sum[r]-sum[x];
                if(left < right)
                {
                    l = x+1;
                    freq[c[i]].pop_front();
                }
                else
                {
                    r = y-1;
                    freq[c[i]].pop_back();

                }
                //cout<<l<<" "<<r<<endl;

            }
        }
        ll ans = sum[r];
        if(l)
            ans-=sum[l-1];
        cout<<ans<<endl;




    }
	return 0;

}
