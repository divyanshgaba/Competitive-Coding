#include <iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;

bool triangle(long long int a,long long int b, long long int c)
{
    if(a+b > c )//&& a+c >b && b+c>a )
        return true;
    return false;

}

int main()
{
    long long int n,l,r;
    cin>>n>>l>>r;
    long long int a[n];
    for(int i =0;i<n;i++)
        cin>>a[i];
    int count =0;
    int flag;
    sort(a,a+n);
    int hi=0;
    int flag1=1,flag2=1;
    for(int i =1;i<n&&(flag1||flag2);i++)
    {
        if(l<a[i]+a[i-1] && flag1)
        {
            hi=i-1;
            flag1 = 0;
        }
        if(r>a[n-i]+a[n-i-1] && flag2)
        {
            r=a[n-i]+a[n-i-1];
            flag2=0;
        }
    }
    for(int k=l;k<=r;k++)
    {
        flag=1;
        for(int i =hi;i<n&&flag;i++)
        {
            for(int j =i+1;j<n&&flag;j++)
            {
                if(triangle(a[i],a[j],k))
                {
                        count++;
                        flag =0;

                }
            }
        }
    }
    cout<<count<<endl;

    return 0;
}
