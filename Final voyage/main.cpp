#include <iostream>
#include <cstring>
using namespace std;
int wt[1003],vt[1003];
int ans[1003][1003];
int answer(int i,int onw,int n,int w)
{

    if(i == n)
    {
        if(wt[i]+onw <= w)
            return vt[i];
        else
            return 0;
    }
    if(ans[i][onw]!=0)
        return ans[i][onw];
    int  temp = answer(i+1,onw,n,w);
    if(onw+wt[i]<=w)
        temp = max(temp,max(answer(i+1,onw,n,w),vt[i]+answer(i+1,onw+wt[i],n,w)));
    ans[i][onw]=temp;
    return temp;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,w;
        cin>>n;
        cin>>w;
        memset(ans,0,sizeof(ans[0][0])*1003*1003);
        for(int i =1;i<=n;i++)
        {
            cin>>wt[i];
        }
        for(int i =1;i<=n;i++)
        {
            cin>>vt[i];
        }
        cout<<answer(0,0,n,w)<<endl;
    }
    return 0;
}
