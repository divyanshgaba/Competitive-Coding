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
const int N = 1e5;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e9 +7;
int n;
int seg[2*N];
void build()
{
    for(int i = n-1;i>0;i--) seg[i] =min(seg[i<<1],seg[i<<1|1]);
}
int query(int l,int r)
{
    int res = MAXN;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res = min(res,seg[l++]);
        if(r&1)
            res = min(res,seg[--r]);
    }
    return res;
}
void update(int p,int val)
{
    for (seg[p += n] = val; p > 1; p >>= 1) seg[p/2] = min(seg[p], seg[p^1]);
}
int main()
{
	//fast;
	int q;
	cin>>n>>q;
	memset(seg,INF,sizeof(seg));
	for(int i =0;i<n;i++)
        cin>>seg[i+n];
    build();
    while(q--)
    {
        char c;
        cin>>c;
        if(c == 'q')
        {
            int l,r;
            cin>>l>>r;
            cout<<query(l-1,r)<<endl;
        }
        else
        {
            int p,val;
            cin>>p>>val;
            update(p-1,val);
        }
    }
	return 0;

}
