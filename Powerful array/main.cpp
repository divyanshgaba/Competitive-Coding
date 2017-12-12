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
const int N = 200000;
const int rtN = 615;
struct Q
{
    int i,l,r,val;
};
bool comp(Q a, Q b)
{
    if(a.val!=b.val)
        return a.val>b.val;
    return a.r>b.r;
}
ll k[1000001];
int main()
{
	//fast;
	int n,m;
	cin>>n>>m;
	ll a[n];
	for(int i = 0;i<n;i++) scanf("%lld",&a[i]);
	Q q[m];
	for(int i = 0;i<m;i++)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].l--,q[i].r--;
        q[i].i=i;
        q[i].val = q[i].l/rtN;
    }
    sort(q,q+m,comp);
    ll answer[m];
    ll ans = 0;
    //unordered_map<ll,ll> k;
    int l = 0,r = 0;
    k[a[0]]++;
    ans = k[a[0]]*k[a[0]]*a[0];
    for(int i = 0;i<m;i++)
    {

        while(r<q[i].r)
        {
            r++;
            ans+=(2*k[a[r]] + 1)*a[r];
            k[a[r]]++;
        }
        while(r>q[i].r)
        {
            ans-=(2*k[a[r]]-1)*a[r];
            k[a[r]]--;
            r--;
        }
        while(l<q[i].l)
        {
            ans-=(2*k[a[l]]-1)*a[l];
            k[a[l]]--;
            l++;
        }
        while(l>q[i].l)
        {
            l--;
            ans+=(2*k[a[l]]+1)*a[l];
            k[a[l]]++;
        }
        answer[q[i].i]=ans;
    }
    for(int i = 0;i<m;i++) printf("%lld\n",answer[i]);
	return 0;

}
