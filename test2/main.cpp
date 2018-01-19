#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    srand(time(NULL));
    ofstream fout ("test8.in");
    ll n = 500000;
    fout<<n<<endl;
    for(int i = 0;i<n;i++)
    {
        fout<<1000000000 <<" ";
    }
    fout<<endl;
    ll q = 500000;
    fout<<q<<endl;
    for(int i = 0;i<q;i++)
    {
        int t = rand()%2;
        if(t==0)
        {
            fout<<0<<" ";
            ll p = rand()%n + 1;
            ll x = 1000000000;
            fout<<p<<" "<<x<<endl;
        }
        else
        {
            ll l = rand()%n + 1;
            ll r = l + rand()%(n - l + 1);
            fout<<1<<" "<<l<<" "<<r<<endl;
        }
    }
    return 0;
}
