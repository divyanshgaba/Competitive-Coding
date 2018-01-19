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
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		vector<vector<ll>> v(n,vector<ll>(n,0));
		for(int i = 0;i<n;i++)
        {

            for(int j = 0;j<n;j++)
            {
                cin>>v[i][j];
            }
            sort(v[i].begin(),v[i].end());
        }
        bool ans = true;
        ll sum = 0;
        ll curmax = v[n-1][n-1] + 1;
        for(int i = n-1;i>=0;i--)
        {
            ans = false;
            for(int j = n-1;j>=0;j--)
            {
                if(v[i][j] < curmax)
                {
                    sum+=(curmax=v[i][j]);
                    ans = true;
                    break;
                }
            }
            if(!ans)
                break;
        }
        if(ans)
            cout<<sum<<endl;
        else
            cout<<"-1"<<endl;
    }
	return 0;

}
