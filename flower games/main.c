#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long joseph (long long n, long long k) {
	if (n == 1)  return 0;
	if (k == 1)  return n-1;
	if (k > n)  return (joseph (n-1, k) + k) % n;
	long long cnt = n / k;
	long long res = joseph (n - cnt, k);
	res -= n % k;
	if (res < 0)  res += n;
	else  res += res / (k - 1);
	return res;
}
int main()
{
    long long t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k=2;
        scanf("%ld",&n);
        printf("%ld\n",joseph(n,k)+1);
    }
    return 0;
}
