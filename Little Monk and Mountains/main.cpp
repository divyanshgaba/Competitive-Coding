#include <iostream>
#include <algorithm>
using namespace std;
long long d[100002];
int binarySearch(int low,int high,long long key)
{
    int mid;
    while(low<high)
    {
        mid=(low+high)/2;
        if(d[mid]<=key)
        {
            low=mid+1;
        }
        else
        {
            high =mid;
        }
    }
    return low;
}
int main()
{
    int n,q;
    cin>>n>>q;
    pair<long long,long long> a[n+1];
    for(int i =1;i<=n;i++)
    {
        cin>>a[i].first>>a[i].second;

    }
    sort(a+1,a+n+1);
    for(int i =1;i<=n;i++)
    {
                d[i] = a[i].second-a[i].first+1;
    }
    for(int i =0;i<q;i++)
    {
        long long x;
        cin>>x;
        long long hold = binarySearch(1,n+1,x);
        //cout<<hold<<endl;
        int j =1;
        while(d[j] <=x)
        {
            x=x-d[j];
        }
        cout<<a[j].first +x<<endl;

    }


    return 0;
}
