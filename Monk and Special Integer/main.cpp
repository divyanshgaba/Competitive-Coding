#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    long long n,x;
    cin>>n>>x;
    long long a[n];
    long long sum[n+1];
    sum[0]=0;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        sum[i+1] =sum[i]+a[i];
    }
   int low=0,high=n,mid;

    while(low<high)
    {
        mid=(low+high)/2;
        long long max =0;
        for(int j =0;j+mid<=n;j++)
        {
            long long sums= sum[j+mid]-sum[j];
            if(max<sums)
                max = sums;
            cout<<" "<<sums<<" ";
        }
        if(max<=x)
            low = mid+1;
        else
            high = mid;

    }
    mid=(low+high)/2;
        long long max =0;
        for(int j =0;j+mid<=n;j++)
        {
            long long sums= sum[j+mid]-sum[j];
            if(max<sums)
                max = sums;
            //cout<<" "<<sums<<" ";
        }
                if(max<=x)
            low = mid+1;
        else
            high = mid;
    //cout<<endl<<a[low-1]<<endl;
    cout<<low-1<<endl;
    return 0;
}
