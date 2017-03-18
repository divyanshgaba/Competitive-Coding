#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
#define ll long long
ll int n,i,a[50010],t;
int main()
{
    fast;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a[0]=0;
        for(i=1;i<=n;i++)
            cin>>a[i];
        a[2]=max(a[1],a[2]);
        for(i=3;i<=n;i++)
        a[i]=max(a[i-1],a[i]+a[i-2]);
        cout<<*(max_element(a+1,a+n+1))<<endl;
    }
    return 0;
}
