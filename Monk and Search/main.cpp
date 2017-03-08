#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int n;
int binarySearch(int low,int high,int key)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return mid;
}
int main()
{

    cin>>n;

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    int q;
    sort(a,a+n);
    cin>>q;
    for(int i =0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        int count=0;
        int hold = binarySearch(0,n,y);
        if(x==0)
        {
            while(hold>=0&&a[hold]>=y)
                hold--;
            count = n-hold-1;
            if(count<0)
                count=0;
        }
        else
        {
            while(hold<n&&a[hold]<=y)
                hold++;
            count =n - hold;
        }
        cout<<count<<endl;
    }
    return 0;
}
