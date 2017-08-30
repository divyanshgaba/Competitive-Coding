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
		string a,b;
		cin>>a>>b;
		unordered_map<char,int> mp;
		for(auto i:b) mp[i]++;
		int ans = 0;
		for(auto i:a)
        {
            if(mp[i]>0)
                ans++,mp[i]-=1;
            else
                break;
        }
        cout<<ans<<endl;
    }
	return 0;

}
