/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool sign(int n)
{
    if(n<0)
        return false;
    return true;
}
void print(int a)
{
    cout<<a<<" ";
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        int dp[n];
        dp[n-1]=1;
        for(int i = n-2;i>=0;i--)
        {
            if(sign(a[i]) == sign(a[i+1]))
                dp[i]=1;
            else
                dp[i]=dp[i+1]+1;
        }
        for_each(dp,dp+n,print);
        cout<<endl;
    }
	return 0;

}
