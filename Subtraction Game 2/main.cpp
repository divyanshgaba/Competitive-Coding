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
const int N = 60;
const int MAXA = 1e4+1;
ll memo[N][MAXA];
int n;
int a[N];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll answer(int i, int g)
{
    if(i == n)
    {
        if(g==1)
            return 1;
        return 0;
    }
    if(memo[i][g]!=-1)
        return memo[i][g];
    return memo[i][g] = answer(i+1,g) + answer(i+1,gcd(g,a[i]));
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        memset(memo,~0,sizeof(memo));
        cin>>n;
        for(int i = 0;i<n;i++)
            cin>>a[i];
        ll ans = 0;
        for(int i = 0;i<n;i++)
            ans+=answer(i+1,a[i]);
        cout<<ans<<endl;
    }
	return 0;

}
