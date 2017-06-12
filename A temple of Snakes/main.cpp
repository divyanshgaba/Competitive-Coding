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
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll n;
        cin>>n;
        ll sum=0;
        ll h[n];
        for(int i =0;i<n;i++)
            cin>>h[i],sum+=h[i];
        ll pre[n];
        pre[0]=1;
        for(int i =1;i<n;i++)
        {
            if(h[i-1] <= h[i])
                pre[i]=min(h[i],pre[i-1]+1);
            else
                pre[i] =1;
        }
        ll suf[n];
        suf[n-1]=1;
        for(int i =n-2;i>=0;i--)
        {
            if(h[i+1] < h[i])
                suf[i] = min(h[i],suf[i+1]+1);
            else
                suf[i] = 1;
        }
        /*for(int i =0;i<n;i++)
        {
            cout<<pre[i]<<" ";
        }

        cout<<endl;
        for(int i =0;i<n;i++)
        {
            cout<<suf[i]<<" ";
        }
        cout<<endl;*/
        ll base = 1;
        for(int i =0;i<n;i++)
        {
            base = max(base,pre[i] + suf[i]);
        }
        ll k = (base+1)/2;
        cout<<sum - k*k<<endl;
    }
	return 0;

}
