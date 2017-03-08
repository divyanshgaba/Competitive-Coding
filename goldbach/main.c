#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
void swap(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
long long partition (long long arr[], long long low, long long high)
{
    long long pivot = arr[high];    // pivot
    long long i = (low - 1);  // Index of smaller element

    for (long long j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(long long arr[], long long low, long long high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        long long pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
bool find3Numbers(long long A[], long long arr_size, long long sum)
{
    long long l, r,i;

    quickSort(A,0,arr_size-1);
    /* Now fix the first element one by one and find the
       other two elements */
    for (i = 0; i < arr_size - 2; i++)
    {

        // To find the other two elements, start two index variables
        // from two corners of the array and move them toward each
        // other
        l = i + 1; // index of the first element in the remaining elements
        r = arr_size-1; // index of the last element
        while (l < r)
        {
            if( A[i] + A[l] + A[r] == sum)
            {
                printf("%lld %lld %lld\n", A[i], A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }

    // If we reach here, then no triplet was found
    printf("counterexample\n");
    return false;
}
long long SieveOfEratosthenes(long long n,long long *arr)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 long long k=0;long long p;long long i;
    for (p=2; p<=sqrt(n); p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }


    for(p=2; p<=n; p++)
       if (prime[p])
          arr[k++]=p;

        return k;
}
int main()
{
    long long test;


        long long n;
        scanf("%lld",&n);
        long long *arr=calloc(10000007,sizeof(long long));
        long long size=SieveOfEratosthenes(n,arr);
        find3Numbers(arr,size,n);

        return 0;
}
