#include <bits/stdc++.h>

#define F(i,p,n) for(LL i=p; i<n; i++)
#define loop(i, n) for(LL i=0; i<n; i++)
#define fast   ios_base::sync_with_stdio(0); cin.tie(0)
#define dd double
#define mem(a, v) memset(a, v, sizeof(a))
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;
int main()
{
    fast;
    LL n,k; cin>>n>>k;
    float a[n],sum=0;
    F(i,0,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    float avg=sum/n;
    cout<<avg;
    LL c=0,flag=1;
    while(0)
    {
        sum+=k;
        n++;
        avg=sum/n;
        cout<<avg<<" ";
        c++;
        if(avg>k) break;
    }
    return 0;
}
