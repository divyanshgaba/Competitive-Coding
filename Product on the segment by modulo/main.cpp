#include<iostream>

using namespace std;

const int N = 1e6;
int n;
long long seg[2*N];
long long p;
void bob()
{
    for(int i = n-1;i>0;i--)
        seg[i]=(seg[i<<1]*seg[i<<1|1])%p;
}
long long satya(long long l,long long r)
{
    long long ans = 1;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans=(ans*seg[l++])%p;
        if(r&1)
            ans = (ans*seg[--r])%p;
    }
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int t_=0;t_<t;t_++)
    {
		int q;
		cin>>n>>p>>q;
		for(int i = 0;i<n;i++)
        {
            cin>>seg[i+n];
        }
        bob();
        int b[n];
        for(int i = 0;i<(q/64)+2;i++)
            cin>>b[i];
        long long x = 0;
        int l,r;
        for(int i = 0;i<=q;i++)
        {
            if(i%64==0)
            {
                l = (b[i/64]+x)%n;
                r = (b[i/64+1]+x)%n;
                if(l>r)
                    swap(l,r);
                x = (satya(l-1,r)+1)%p;
            }
            else
            {
                l = (l+x)%n;
                r = (r+x)%n;
                if(l>r)
                    swap(l,r);
                x=(satya(l-1,r)+1)%p;
            }
            //cout<<l<<" "<<r<<" "<<x<<endl;
        }
        cout<<x<<"\n";

    }
	return 0;

}
