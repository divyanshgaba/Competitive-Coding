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
const int INF = 1e9;
int a[2*N];
int n;

void build()
{
    for(int i = n-1;i>0;i--) a[i] = min(a[i<<1],a[i<<1|1]);
}
int query(int l,int r)
{
    int res = INF;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res = min(res,a[l++]);
        if(r&1)
            res = min(res,a[--r]);
    }
    return res;
}

int main()
{
	fast;
	int q;
    cin>>n;
    for(int i  =0;i<n;i++) cin>>a[i+n];
    build();
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r+1)<<endl;
    }
	return 0;

}
