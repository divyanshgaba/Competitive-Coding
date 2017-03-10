#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        double n;
        cin>>n;
        double ans = 5*n*n +4;
        double asn = 5*n*n -4;
        //cout<<ans<<endl;
        unsigned long long s= sqrt(ans);
        //cout<<s*s;
        unsigned long long x = sqrt(asn);
        if(s*s==ans||x*x==asn)
            cout<<"IsFibo";
        else
            cout<<"IsNotFibo";
        cout<<endl;
    }
    return 0;
}
