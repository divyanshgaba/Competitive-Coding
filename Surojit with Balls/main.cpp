#include <iostream>
#include <algorithm>
using namespace std;
int mem[100005];
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        int a[n+1];
        mem[0]=a[0]=0;
        int ans =0;
        for(int i =1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>m)
                mem[i]=0;
            else
            {
                if(a[i]<=m)
                    mem[i]=a[i];
                if(a[i-1]<=m)
                    mem[i]+=mem[i-1];
            }
            ans=max(ans,mem[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
