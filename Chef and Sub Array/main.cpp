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
const int N = 1e5;
int n;
int sum[4*N+1];
int n2,n4;

void build()
{
    for(int t = n2-1;t>0;t--) sum[t] = max(sum[t<<1],sum[t<<1|1]);
}
int query(int l,int r)
{

    int res = 0;
    for(l+=n2,r+=n2;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res = max(res,sum[l++]);
        if(r&1)
            res = max(res,sum[--r]);
    }
    return res;
}

int main()
{
	fast;
	int k,p;
	cin>>n>>k>>p;
	n2=2*n,n4=2*n2;
	int a[n2];
	for(int i = 0;i<n;i++)
        cin>>a[i],a[i+n]=a[i];
    for(int i = 0;i<2*n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    string s;
    cin>>s;
    sum[0+n2] = a[0];
    for(int i = 1;i<n2;i++)
    {
        if(i < k )
            sum[n2+i] =sum[n2+i-1] + a[i];
        else
            sum[n2+i] = sum[n2+i-1] + a[i] - a[i-k];
    }
    for(int i = 0;i<n4;i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    build();
    for(int i = 0;i<n4;i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    int pos = n;
    for(auto i:s)
    {
        if(i == '?')
        {
            cout<<query(pos+1,pos + n - k  +1)<<endl;
        }
        else
        {
            pos--;
            if(pos == 0)
                pos = n;
        }
    }
	return 0;

}
