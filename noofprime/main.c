void primeFactors(int n)
{
    int i,count=0;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        count++;
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for ( i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            count++;
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        count++;
        printf("%d",count);
}

/* Driver program to test above function */
int main()
{

    primeFactors(n);
    return 0;
}
