#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i =0;i<n;i++)
            cin>>a[i];
        int b[n];
        vi ind[n+1];
        ind[1].PB(0);
        b[0]=1;
        for(int i =1;i<n;i++)
        {
            if(a[i]==a[i-1])
                b[i]=b[i-1]+1;
            else
                b[i]=1;

            ind[b[i]].PB(i);
        }
        int blsize[n];
        blsize[n-1] =1;
        int cnt =1;
        for(int i =n-2;i>=0;i--)
        {
            if(b[i] >= b[i+1])
            {
                cnt =1;

            }
        }
        for(int i =0;i<q;i++)
        {
            int l,r,k;
            cin>>l>>r>>k;
            //changing to 0-index
            l--,r--;
            int ans = upper_bound(ind[k].begin(),ind[k].end(),r) - lower_bound(ind[k].begin(),ind[k].end(),l);
            //cout<<s<<" - "<<f<<" = "<<s-f<<endl;
            if(b[l]!=1)
            {
                // get location where the block starts
                int loc = l - b[l] +1;
                //get size of that block
                int len = mp[loc];

                //if it was counted
                if(b[l] <= k)
                    ans--;

                //if it should be counted
                if(len - b[l] +1 >=k)
                    ans++;

                //no block completely lies within the range
                int endsAt = len + loc-1;
                if(endsAt >= r)
                {
                    if(r-l +1 < k)
                        ans--;
                }

            }
            cout<<ans<<endl;

        }
    }
	return 0;

}
