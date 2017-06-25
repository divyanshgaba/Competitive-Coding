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
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i = 0;i<n/2;i++)
        {
            mp[s[i]]++;
        }
        for(int i = n/2 +(n&1?1:0);i<n;i++)
        {
            mp[s[i]]--;
        }
        bool ans = true;
        for(auto i:mp)
        {
            if(i.S!=0)
                ans = false;
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";



    }
	return 0;

}
