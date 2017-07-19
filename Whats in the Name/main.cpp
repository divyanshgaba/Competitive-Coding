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

void solve()
{
    string s,k="";
    cin>>s;
    int n = s.length();
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i] == '=')
            continue;
        k += s[i];
    }
    int l = k.length();
    int cn =1,h=0,t=0;
    for(int i = 0;i<l;i++)
    {
        if(k[i] == '<')
            t++,h=0;
        else
            h++,t=0;
        ans = max(ans,max(h,t));
    }
    cout<<ans+1<<endl;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
