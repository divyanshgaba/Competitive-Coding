#include <iostream>
long long m;
using namespace std;

long long primeFactors(long long n)
{
    long long c =1;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        c *= 2%m;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            c *= i%m;
            n = n/i;
        }
    }
    if(n>2)
        c *=n%m;
    return c;
}

int main()
{
    long long test;
    cin>>test;
    while(test--)
    {
        long long a,n;
        cin>>a>>n>>m;

    }
    return 0;
}
