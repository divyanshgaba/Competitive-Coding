#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int N =10001;
ll sum[N];
double cek[N];
const double e =  2.7182818284;

int main()
{
    ll te =0;
    ifstream fin("check.txt");
    while(!fin.eof())
    {
        ll a, b;
        fin>>a>>b;
        sum[a] =sum[a-1] + b;
        ll ans = e *a*(a+1)/2 - (a-1)/2;
        //if(ans != sum[a])        cout<<ans<<" "<<sum[a]<<" "<<ans-sum[a]<<endl;
        te +=llabs(ans-sum[a]);
     }
     cout<<sum[N-1]<<endl;
     cout<<te<<endl;
     cout<<double(te)/double(N)<<endl;


	return 0;
}
