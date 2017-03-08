#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double d[100001];
int binarySearch(int low,int high,double key)
{
    int mid;
    while (low != high)
    {
        int mid = (low + high) / 2;
        if (d[mid] <= key)
        {

            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return high;
 }
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        long long a,b;
        cin>>a>>b;
        d[i] = sqrt((a*a)+(b*b));
        //cout<<d[i]<<endl;
    }
    sort(d,d+n);
    int q;
    cin>>q;
    for(int i =0;i<q;i++)
    {
        double r;
        cin>>r;
        int count =0;
        int hold = binarySearch(0,n,r);
        cout<<hold<<endl;
    }
    return 0;
}
