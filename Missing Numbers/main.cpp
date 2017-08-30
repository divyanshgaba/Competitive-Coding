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
    int n,m,x;
    cin>>n;
    unordered_map<int,int> mp,mt;
    for(int i = 0;i<n;i++) cin>>x,mp[x]++;
    cin>>m;
	for(int i = 0;i<m;i++) cin>>x,mt[x]++;
	set<int> s;
	for(auto i:mt)
    {
        if(i.S != mp[i.F])
            s.insert(i.F);
    }
    for(auto i:s)
        cout<<i<<" ";
	return 0;

}
