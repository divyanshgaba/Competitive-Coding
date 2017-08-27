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
        string s;
        cin>>s;
        int n = s.length();
        map<string,int> mp;
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                string k = s.substr(i,j-i+1);
                sort(k.begin(),k.end());
                mp[k]++;
            }
        }
        int ans = 0;
		for(auto i:mp)
        {
            ans+= i.S*(i.S-1)/2;
        }
        cout<<ans<<endl;
    }
	return 0;

}
