#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
{
    if(n)
        return n*factorial(n-1);
    else
        return 1;
}
char *divisor(int n)
{
    int i;
    if(n>1)
    {
        printf("Divisors are:\t");
        for (i=1;i<=n;i++)
        {
            if(n%i==0)
                printf("%d ",i);
        }
    }
    else
        printf("No divisors");
}
int main()
{
    int n;
    printf("\t=====To print factorial and all divisors of a number=====\n"
           "Enter a non-negative number:\t");
    scanf("%d",&n);
    printf("Factorial is:\t%d\n",factorial(n));
    divisor(n);
    return 0;
}
