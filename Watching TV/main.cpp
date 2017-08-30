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
		unordered_map<int,int> mp;
		for(int i = 0;i<n;i++)
        {
            string s;
            int f;
            cin>>s>>f;
            mp[f]++;
        }
        int ans = 0,freq=-1;
        for(auto i:mp)
        {
            if(freq<i.S)
                ans = i.F,freq = i.S;
            else if(freq == i.S)
            {
                if(ans >i.F)
                    ans = i.F;
            }
        }
        cout<<ans<<endl;
    }
	return 0;

}
