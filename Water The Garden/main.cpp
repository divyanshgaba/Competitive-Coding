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
		int n,k;
		cin>>n>>k;
		vector<int> v;
		for(int i = 0;i<k;i++)
        {
            int x;
            cin>>x;
            x--;
            v.PB(x);
        }
        bool vis[n];
        memset(vis,false,sizeof(vis));
        int ans = 0;
        for(int i = 0;i<=n;i++)
        {
            bool still = true;
            for(int j = 0;j<n;j++)
            {
                if(vis[j]==false)
                {
                    still = false;
                    break;
                }
            }
            if(still)
            {
                ans = i;
                break;
            }
            for(auto j:v)
            {
                if((j+i)< n)
                    vis[j+i] = true;
                if((j-i)>=0)
                    vis[j-i] = true;
            }
        }
        cout<<ans<<endl;
    }
	return 0;

}
