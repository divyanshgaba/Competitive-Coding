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
const int INF = 1e9;
const int N = 1e5+5;
int n;
vector<int> seg[2*N];
int zero[N];
void init()
{
    memset(zero,0,sizeof(zero));
    for(int i = 0;i<2*N;i++) seg[i].clear();
}
void build()
{
    for(int i = n-1;i>0;i--) merge(seg[i<<1].begin(),seg[i<<1].end(),seg[i<<1|1].begin(),seg[i<<1|1].end(),back_inserter(seg[i]));
}


int query(int l,int r,int k)
{
    int res = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res+=(upper_bound(seg[l].begin(),seg[l].end(),k) - lower_bound(seg[l].begin(),seg[l].end(),k)),l++;
        if(r&1)
            --r,res+=(upper_bound(seg[r].begin(),seg[r].end(),k) - lower_bound(seg[r].begin(),seg[r].end(),k));
    }
    return res;
}

int main()
{
	//fast;
	int test;
	cin>>test;
	while(test--)
    {
        init();
        int q;
        cin>>n>>q;
        int a[n];
        for(int i =0;i<n;i++)
            cin>>a[i];
        seg[n].PB(1);
        for(int i = 1;i<n;i++)
        {
            if(a[i] == a[i-1])
                seg[i+n].PB(seg[i+n-1][0] + 1);
            else
                seg[i+n].PB(1);
        }
        // segment tree
        build();
        for(int i =0;i<q;i++)
        {
            int l,r,k;
            cin>>l>>r>>k;
            int ans = query(l-1,r,k);
            if(seg[l-1+n][0] != 1)
            {
                if(k < seg[l-1+n][0])
                {
                    if((a[l-1] == a[l-1 + k-1]) && ((seg[l-1 + k-1 + n][0] - seg[l-1 + n][0] + 1) == k))
                        ans++;
                }
                else
                {
                    if((a[l-1] != a[l-1 + k-1]) || ((seg[l-1 + k-1 + n][0] - seg[l-1 + n][0] +1 )!= k))
                        ans--;
                }
            }
            cout<<ans<<endl;

        }
    }
	return 0;

}
