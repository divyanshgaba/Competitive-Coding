#include <iostream>
#include <cstring>
using namespace std;
int a[100001],b[100001],c[100001];
long long dp[1001][1001];
long long ans(int st,int en)
{

    if(st==en)
        return 0;
    if(st>en)
        return 1000000;
            //cout<<st<<" "<<en<<endl;
    if(dp[st][en]!=0)
        return dp[st][en];
    if(en==st+1)
        return a[st];
    if(en==st+2)
        return b[st];
    if(en==st+3)
        return c[st];
    long long temp = a[st] + ans(st+1,en);
    if(en-st>=2)
        temp=min(temp,b[st]+ans(st+2,en));
    if(en-st>=3)
        temp=min(temp,c[st]+ans(st+3,en));
    dp[st][en]=temp;
    return temp;

}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp[0][0])*1001*1001);
        for(int i =0;i<n-1;i++)
        {
            cin>>a[i];
        }
        for(int i =0;i<n-2;i++)
        {
            cin>>b[i];
        }
        for(int i =0;i<n-3;i++)
        {
            cin>>c[i];
        }
        long long sum=0;
        for(int i =0;i<n-1;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                sum+=ans(i,j);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}






