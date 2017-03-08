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

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{

    while(1)
    {
        int n,i,j;
        int count=0;
        scanf("%d",&n);
        if(n<=0)
        {
            break;
        }
        int array[2001];
        for(i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
        }

        mergeSort(array, 0, n - 1);
        for(i=0;i<n-1;i++)
        {
            if(array[i]==array[i-1])
                continue;
            for(j=i+1;j<n;j++)
            {
                int x= array[i]+array[j];
                int l=0,r=n-1;
                int mid=(r-l)/2;
                while(l<=r)
                {
                    mid=(r-l)/2;
                    if(x=array[mid])
                        break;
                    else if(x<array[mid])
                    {
                        r=mid-1;

                    }
                    else
                        l=mid+1;
                }
                if(x<=array[mid])
                {
                    count=count+n-2-mid;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
