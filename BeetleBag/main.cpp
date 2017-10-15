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

int max(int a, int b) { return (a > b)? a : b; }
const int N = 1e3;
int wt[N],val[N];
int dp(int W, int n)
{
   int i, w;
   int K[n+1][W+1];
    for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int c,n;
		cin>>c>>n;
		for(int i = 0;i<n;i++)
            cin>>wt[i]>>val[i];
        cout<<dp(c,n)<<endl;
    }
	return 0;

}
