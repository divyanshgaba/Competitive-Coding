#include <iostream>
#define MOD 1000000007
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        n=n%MOD;
        long long ans = (n*n)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
