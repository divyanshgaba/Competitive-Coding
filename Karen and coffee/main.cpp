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
const int N = 2e5 + 1;
ll arr[N];
vector<ll> seg[2*N];

void build()
{
    for(int i = N-1;i>0;i--)
        merge(seg[i<<1].begin(),seg[i<<1].end(),seg[i<<1|1].begin(),seg[i<<1|1].end(),back_inserter(seg[i]));
}

int k,n;
ll query(int l,int r)
{
    ll res =0;
    for(l+=N,r+=N;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res += (seg[l].size()- (lower_bound(seg[l].begin(),seg[l].end(),k) -seg[l].begin())),l++;
        if(r&1)
            --r,res += (seg[r].size() - (lower_bound(seg[r].begin(),seg[r].end(),k) - seg[r].begin()));
    }

    return res;
}

int main()
{
	fast;
	int q;
	cin>>n>>k>>q;
	for(int i =0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        arr[l]++,arr[r+1]--;
    }
    for(int i = 1;i<N;i++)
    {
        arr[i] += arr[i-1];
        seg[i+N].PB(arr[i]);
    }
    build();
    for(int i = 0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r+1)<<endl;
    }

	return 0;

}
