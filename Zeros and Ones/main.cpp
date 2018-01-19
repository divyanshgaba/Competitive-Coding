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
const int N = 1e6+7;
int t[2*N];
int n;
void build()
{
    for(int i = n-1;i>0;i--)t[i]=t[i<<1]+t[i<<1|1];
}
void modify(int p)
{
    for(t[p+=n]=0;p>1;p>>=1)
        t[p>>1] = t[p]+t[p^1];
}
int query(int l,int r)
{
    int ans = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans+=t[l++];
        if(r&1)
            ans+=t[--r];
    }
    return ans;
}
int main()
{
	fast;
	cin>>n;
	for(int i = 0;i<n;i++)
        t[i+n]=1;
    build();
    int q;
	cin>>q;
	while(q--)
    {
        int t,k;
        cin>>t>>k;
        if(t==0)
        {
           modify(k-1);

        }
        else
        {
            int ans = n+1;
            int lo = 0,hi=n-1;
            while(lo<=hi)
            {
                int mid = (lo+hi)/2;
                int sum = query(0,mid+1);
                if(sum>=k)
                {
                    ans =min(ans,mid+1);
                    hi=mid-1;
                }
                else
                    lo = mid+1;
            }
            if(ans<n+1)
                cout<<ans<<endl;
            else
                cout<<-1<<endl;
        }
        //for(int i = 0;i<n;i++)            cout<<::t[i+n]<<" ";        cout<<endl;
    }
	return 0;

}
