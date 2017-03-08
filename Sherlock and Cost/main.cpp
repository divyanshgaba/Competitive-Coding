#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
long long b[100002];
long long n;
long long ans[100002][101];
long long solve(long long i,long long v)
{
    if(i==0)
        return 0;
    if(ans[i][v]!=-1)
        return ans[i][v];
    long long temp =abs(v-1)+ solve(i-1,1);
    temp = max(temp,abs(v-b[i])+solve(i-1,b[i]));
    ans[i][v]=temp;
    return temp;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        memset(ans,-1,(n+1)*101*sizeof(ans[0][0]));
        for(int i =1;i<=n;i++)
            cin>>b[i];
        long long s=0;
        s=solve(n-1,1);
        s=max(s,solve(n-1,b[n]));
        cout<<s<<endl;

    }
    return 0;
}
