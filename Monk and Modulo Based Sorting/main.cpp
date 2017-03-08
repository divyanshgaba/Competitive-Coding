#include <iostream>
#include <algorithm>
using namespace std;

bool mycomp(pair<int,int> a,    pair<int,int> b)
{
    return a.first<b.first;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i]%k;
    }
    for(int i =0;i<n;i++)
    {
        int flag =0;
        for(int j =0;j<n-1;j++)
        {
            if(b[j]>b[j+1])
            {
                swap(b[j],b[j+1]);
                swap(a[j],a[j+1]);
               // flag =1;
           }
        }
      //  if(flag ==1)
           // break;
    }
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
