#include <iostream>
#include<math.h>

#define MOD 1000000007

long long int a,b,c,d;
using namespace std;

void fast_fib(long long int n,long long int ans[],long long f0, long long f1)
{
    if(n == 0)
    {
        ans[0] = f0;
        ans[1] = f1;
        return ;
    }
    fast_fib((n/2),ans,f0,f1);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }

}


int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        long long f0,f1,num,ans[2]={0};
        cin>>f0>>f1>>num;

        fast_fib(num-2,f0,f1);
        long long fn2=ans[0];
        long long fn1 = ans[1];
        long long ok = ((long long int)pow((fn1+fn2)%MOD,2)%MOD) + fn1*fn2%MOD;
        cout<<ok<<endl;
    }
    return 0;
}


