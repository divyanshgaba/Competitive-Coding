#include <stdio.h>
#include <stdlib.h>
void swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (double arr[], int low, int high)
{
    double pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
int j;
    for (j = low; j <= high- 1; j++)
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
void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    int i;
    double w[5000],s[5000],a[5000];
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&w[i],&s[i]);
        //w[i]+=10;
    }
    double low=0.454545,high=1.666667;
    double mid;
    while(high-low>1e-7)
    {
        int flag=0;

        mid = (low+high)/2.0;
        for(i=0;i<n;i++)
        {
            a[i]=s[i]-mid*w[i];
        }
        quickSort(a,0,n-1);
        for(i=0;i<n/2;i++)
        {
            if(a[i]+a[n-1-i]<20*mid)
            {
                flag=1;
                printf("hi");
                break;
            }

        }
        if(flag==1)
        {
            high=mid;
        }
        else
            low=mid;
    }
    printf("%lf",mid);

    return 0;
}
