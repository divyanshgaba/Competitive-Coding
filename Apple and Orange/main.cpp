#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main()
{
    fast
    int s,t,a,b,m,n;
    cin>>s>>t>>a>>b>>m>>n;
    int orange =0,apple =0;
    for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x+a >=s &&x+a<=t)
            apple++;
    }
    for(int i =0;i<m;i++)
    {
        int x;
        cin>>x;
        if(x+b >=s &&x+b<=t)
            orange++;
    }
    cout<<apple<<endl<<orange<<endl;
    return 0;
}
