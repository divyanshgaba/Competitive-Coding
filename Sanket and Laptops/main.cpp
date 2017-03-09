#include <iostream>
#include <cstring>
using namespace std;
int ans[10010];
int n;
int a[101];
int answer(int sum,int i)
{
    //cout<<sum<<" "<<i<<endl;
    int temp=0;
    if(i==n)
        return 0;
    if(ans[sum]==0)
    {
        ans[sum]=1;
        temp =1;
    }
    for(int j = i+1;j<n;j++)
    {
        temp += answer(sum+a[j],j);
    }
    return temp;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(ans,0,sizeof(ans[0])*10010);
        int sum = answer(0,0);
        for(int i =0;i<n;i++)
        {
            sum+=answer(a[i],i);
        }
        cout<<sum<<endl;
    }
    return 0;
}
