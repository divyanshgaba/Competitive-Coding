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

bool vis[26];
int main()
{
	fast;
    string s;
    bool ans = true,all = true;
    unordered_map<char,int> mp;

    while(cin>>s)
    {
        for(auto i:s)
        {
            vis[tolower(i)-97] = true;
        }
    }
    for(int i = 0;i<26;i++) if(vis[i]== false) ans = false;
    if(ans)
        cout<<"pangram\n";
    else
        cout<<"not pangram\n";
	return 0;

}
