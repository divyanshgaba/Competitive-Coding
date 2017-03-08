#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(double arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    double L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(double arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        double m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    double solx[n],soly[n];
    double shelx[n],shely[n];
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&solx[i],&soly[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&shelx[i],&shely[i]);
    }
    double dist=0;
    for(i=0;i<n;i++)
    {
        int it,jt;
        double temp=10e12;
        for(j=0;j<n;j++)
        {
            double dist=fabs(solx[j]*solx[j]-shelx[i][i]) - fabs(soly[j*soly[j]-shely[i]*shely[i]);
            dist=fabs(dist);
            dist=sqrt(dist);
            if(temp>dist)
            {
                it=i;
                jt=j;
                temp=dist;
            }
            shel[i],

        }
        if(temp>dist)
                dist+=temp;
    }
    printf("%lf",dist);

}
