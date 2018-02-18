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

bool cmp(pair<pi,int> a,pair<pi,int> b)
{
    return a.F.F<b.F.F;
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
		vector<pair<pi,int>> v;
        int ans[n];
        int t = 1;
		for(int i = 0;i<n;i++)
        {
            int l,r;
            cin>>l>>r;
            if(r<t)
            {
                ans[i]=0;
            }
            else
            {
                t = max(t,l);
                ans[i]=t++;
            }
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }

	return 0;

}
