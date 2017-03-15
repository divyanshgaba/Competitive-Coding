#include <iostream>
#include <array>
#include <cmath>
#define MAX 200011
using namespace std;
int a[MAX+1];
int d[MAX+1];
int n;
void divisor(int n)
{
    int rn = sqrt(n);
    for (int i=1; i<=rn; i++)
    {
        if (n%i==0)
        {
            if (n == i*i)
                d[i]+=1;

            else
                {
                    d[i]+=1;
                    d[n/i]+=1;
                }
        }
    }
}
int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        divisor(a[i]);
    }
    int t;
    cin>>t;
    for(int i =0;i<t;i++)
    {
        int p,q;
        cin>>p>>q;
        int count=0;
        int pq = p*q;
        if(q<p)
            swap(p,q);
        if(q%p==0)
        {
            count=d[p];
        }
        else
        {   count = d[p]+d[q];
            if(p<1414)
            {
                if(pq<MAX)
                    count-=d[pq];
            }
        }
        cout<<count<<endl;

    }
    return 0;
}
