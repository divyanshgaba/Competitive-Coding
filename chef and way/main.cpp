#include <iostream>
#define MOD 1000000007
using namespace std;
int n,k;
int a[100002];
int ans[100002];
int answer(int i)
{
    if(i == n)
    {
        return a[i];
    }
    if(ans[i]!=0)
        return ans[i];
    //cout<<i<<" "<<a[i]<<endl;
    int temp = (a[i]*answer(i+1))%MOD;
    for(int j =2;j<=k&&i+j<=n;j++)
    {

        temp =min(temp,((a[i]*(answer(i+j)%MOD))%MOD));
    }
    ans[i]=temp%MOD;
    return temp%MOD;
}

int main()
{
    cin>>n>>k;
    for(int i =1;i<=n;i++)
        cin>>a[i];
    cout<<answer(1)<<endl;
    return 0;
}
