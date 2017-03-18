#include <iostream>

using namespace std;
int a[1001][1001];
int nearest(int low,int high,int val,int i)
{
    int mid;
    while(low<high)
    {
        mid = (low+high)/2;
        if(a[i][mid]==val)
            return 0;
        if(a[i][mid]<val)
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    if(low==0)
        return abs(val-a[i][0]);
    return min(abs(val-a[i][low]),abs(val-a[i][low-1]));

}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }
        sort(a[i],a[i]+m);
    }


    return 0;
}
