#include<stdio.h>
#include<string.h>
const int MAX = 1e9;
const int  N = 350;
char x[N],y[N];
int n,m,k;
int dp[N][N][N];
int solve(int i,int j,int k);
int main()
{
    memset(dp,~0,sizeof(dp));
	scanf("%d %d %d",&n,&m,&k);
	scanf("%s",x);
	scanf("%s",y);
	int answer = solve(n-1,m-1,k);
	if(answer >=MAX)
        printf("-1\n");
    else
        printf("%d",answer);
	return 0;

}
int solve(int i,int j,int k)
{
    if(k == 0)
        return 0;
    if(i==-1 || j == -1)
        return MAX;
    if(dp[i][j][k]>=0)
        return dp[i][j][k];
    int temp1 = solve(i-1,j,k);
    int temp2 = solve(i,j-1,k);
    int temp3 =  solve(i-1,j-1,k-1)+((x[i]-97)^(y[j]-97));
    int ans = temp1;
    if(ans>temp2)
        ans = temp2;
    if(ans>temp3)
        ans = temp3;
    dp[i][j][k]=ans;
    return ans;
}
