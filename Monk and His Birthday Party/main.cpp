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
int w[100001];
int l[100001];
unordered_map<int,ll> mp;
bool check(ll t)
{

}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n,m;
        cin>>n>>m;
        mp.clear();
        for(int i =0;i<m;i++) cin>>l[i];
        int wei =0;
        for(int i =0;i<n;i++) cin>>w[i],mp[w[i]]=0;
        int c;
        for(int i =0;i<n;i++) cin>>c,mp[w[i]] += c;
        sort(l,l+m);
        sort(w,w+n);
        ll low =1,high = 1e13,ans =-1;
        while(low<=high)
        {
            ll mid = (low +high)/2;
            if(check(mid))
            {
                high = mid-1;
                ans = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;

}
