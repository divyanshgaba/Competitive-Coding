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
const int N = 1e5;
int dp[N];
int main()
{
	fast;
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int cur = a[0];
    int curbest = 1;
    dp[0]=1;
    for(int i = 1;i<n;i++)
    {
        if(cur<=a[i])
            dp[i]=dp[i-1]+1,cur=a[i];
        else
        {
            dp[i]=1;
            cur=a[i];
        }
        curbest = max(curbest,dp[i]);
    }
    cout<<curbest<<endl;
	return 0;

}
