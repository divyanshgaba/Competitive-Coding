#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

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
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int i;
        int range=0;
        int *size=calloc(n,sizeof(int));
        int *sorted=calloc(n,sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&size[i]);
        }
        mergeSort(size,0,n-1);
        for(i=1;i<n;i++)
        {
            sorted[i]=abs(size[i]-size[i-1]);
        }
        sorted[0]=abs(size[n-1]-size[0]);
        mergeSort(sorted,0,n-1);
        int temp=n-k;
        for(i=0;i<temp;i++)
        {
            range+=sorted[i];
        }
        printf("%d\n",range);


    }
    return 0;
}
