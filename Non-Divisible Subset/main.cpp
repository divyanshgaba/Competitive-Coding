#include <iostream>
#include <algorithm>
using namespace std;
int c[101];
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int count =0;
    for(int i =1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]%k]++;
    }
    if(k%2==0)
        c[k/2] = min(1,c[k/2]);
    for(int i =1;i<=k/2;i++)
    {
        count+= max(c[i],c[k-i]);

    }
    count+=min(c[0],1);
    cout<<count<<endl;
    return 0;
}
