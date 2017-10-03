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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int t = 0,ans=0;
	bool vis[26];
	memset(vis,0,sizeof(vis));
	for(int i = 0;i<n;i++)
    {
        if(islower(s[i]))
        {
            if(!vis[s[i]-'a'])
                t++,vis[s[i]-'a']=true;
        }
        else
        {
            ans = max(t,ans);
            t = 0;
            memset(vis,0,sizeof(vis));
        }
    }
    ans = max(t,ans);
    cout<<ans<<endl;
	return 0;

}
