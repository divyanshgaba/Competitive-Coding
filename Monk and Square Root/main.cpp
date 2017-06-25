#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        ll n,m;
        cin>>n>>m;
        ll ans = -1;
        for(ll i = 0;i<m;i++)
        {
            if((i*i)%m == n)
            {
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
