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
const int N = 1e5+5;
ll n,a[N];
ll dp[N][51];
int ks;

int answer(int i,int k)
{
    if(k<0)
        return -1;
    if(dp[i][k]!=-1)
        return dp[i][k];

    int temp = 0;
    for(int j = i+1;j<n;j++)
    {
        if(k >= abs(a[i]-a[j]))
            temp = max(temp, 1 + answer(j, k - abs(a[i]-a[j])));
        if(a[i] == a[j])
            break;
    }
    return dp[i][k] = temp;
}
int main()
{
	fast;
	cin>>n>>ks;
	memset(dp,~0,sizeof(dp));
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<1 + answer(0,ks)<<endl;
	return 0;


}
