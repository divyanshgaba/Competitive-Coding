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
    bool vis[n][26];
    memset(vis,false,sizeof(vis));
    for(int i = 0;i<n;i++)
    {
        string s;
        cin>>s;
        for(auto j:s)
            vis[i][j-97] = true;
    }
    int ans = 0;
    for(int i = 0;i<26;i++)
    {
        int temp = 0;
        for(int j = 0;j<n;j++)
        {
            if(vis[j][i]!= true)
                break;
            temp++;
        }
        if(temp == n)
            ans+=1;
    }
    cout<<ans<<endl;

	return 0;

}
