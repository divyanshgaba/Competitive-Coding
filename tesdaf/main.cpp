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
	int t;
	cin>>t;
	while(t--)
    {
        string s;
        cin>>s;
        unordered_map<char,int> mp;
        for(auto i:s) mp[i]++;
        int ans = min(mp['I'],mp['E']/3);
        cout<<ans<<endl;
    }

	return 0;

}
