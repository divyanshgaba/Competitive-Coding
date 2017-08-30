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
		int m,n;
		cin>>m>>n;
		int a[n];
		vector<int> v[10001];
		for(int i = 0;i<n;i++) cin>>a[i],v[a[i]].PB(i);
		pi ans;
		int flag = 0;
		for(int i =0;i<n&&!flag;i++)
        {
            int ele = m - a[i];
            if(ele<=0)
                continue;
            for(auto j : v[ele])
            {
                if(j!=i)
                {
                    ans = MP(min(i,j),max(i,j)),flag = 1;
                    break;
                }
            }
        }
        cout<<ans.F+1<<" "<<ans.S+1<<endl;
    }
	return 0;

}
