#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MOD 1000000007
/*void primeFactors(int n,int *arr)
{
    int i;
    int flag=0,k=0;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        flag=1;
        n = n/2;
    }
    if(flag==1)
        arr[k++]=2;
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (i = 3; i <= sqrt(n); i = i+2)
    {
        flag=0;
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            flag=1;
            n = n/i;
        }
        if(flag==1)
            arr[k++]=i;
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2)
        arr[k++]=n;
}*/
void SieveOfEratosthenes(int n,int *arr)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    int k=0,p,i;
    memset(prime, true, sizeof(prime));

    for (p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (p=2; p<=n; p++)
       if (prime[p])
          {arr[k++]=p;}
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,a,b,j;
        scanf("%d %d %d",&n,&a,&b);
        int i;
        long long sum=0;
        int arr[10000]={};
        SieveOfEratosthenes(n,arr);
        for(i=0;arr[i]<=n;i++)
        {
            if(arr[i]>=b)
                break;
            else if(arr[i]>=a)
                sum=(sum+i)%MOD;
        }


        printf("%lld\n",sum);
    }
    return 0;
}
