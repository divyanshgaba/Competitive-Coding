#include <iostream>
#include <cstring>
using namespace std;
int mem[100005];
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a[n+1];
        memset(mem,0,sizeof(mem));
        int sum =0;
        for(int i =1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>=a[i-1])
                mem[i]=mem[i-1]+1;
            else
                mem[i]=1;
        }

        for(int i =1;i<=n;i++)
            sum+=mem[i];
        cout<<sum<<endl;
    }
    return 0;
}
