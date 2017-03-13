#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
array<array<int,300>,300>  a;
array<array<int,300>,300>  b;
int loc[9500][2];
int cost(array<int,300> a)
{
    int sum =0;
    for(int j =0;j<n;j++)
    {
        sum+=pow(loc[a[j]][1]-j,2);
    }
    return sum;
}


int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>a[i][j];
            loc[a[i][j]][0]=i;
            loc[a[i][j]][1]=j;

        }
    }
    b=a;
    for(int i =0;i<n;i++)
    {
        array<int,300> d=a[i];
        array<int,300> e=a[i];
        sort(d,d+n);
        sort(e,e+n,greater<int>());
        if(cost(d) > cost(e))
            b[i]=e;
        else
            b[i]=d;
    }


    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
