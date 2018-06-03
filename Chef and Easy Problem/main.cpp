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

int main()
{
	fast;
	int n,q;
	cin>>n>>q;
	int a[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    int x[n+1][32];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<31;j++)
        {
            x[i][j] = ((1<<j)&a[i])!=0;
            if(i)
                x[i][j]+=x[i-1][j];
        }

    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int y[32];
        int ans = 0;
        r--,l--;
        for(int i = 0;i<31;i++)
        {
            y[i] = x[r][i];
            if(l)
                y[i]-=x[l-1][i];
            int one = y[i];
            int zero = r-l+1-one;
            if(one<zero)
                ans|=(1<<i);
            //cout<<i<<" "<<one<<" "<<zero<<endl;
        }
        cout<<ans<<endl;

    }
	return 0;

}
