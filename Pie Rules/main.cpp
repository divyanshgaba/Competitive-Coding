
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    reverse(a,a+n);
    int dp[n],pre[n];
    dp[0]=a[0],pre[0]=a[0];
    for(int i = 1;i<n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int i = 1;i<n;i++)
    {
        int mx = 0;
        for(int j = 0;j<i;j++)
            mx= max(mx,dp[j]);
        dp[i] = max(a[i]-dp[i-1]+pre[i-1],mx);

    }
    cout<<pre[n-1]-dp[n-1]<<" "<<dp[n-1]<<endl;

	return 0;

}
