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
const int INF = 1e6;
int x;
int count(string a, string b)
{
    int m = a.length();
    int n = b.length();
    int lookup[m + 1][n + 1];
    memset(lookup,0,sizeof(lookup));
    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        lookup[0][i] = 0;
     for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] != b[j - 1])
                lookup[i][j] = lookup[i - 1][j];


            else
                lookup[i][j] =  lookup[i - 1][j] + lookup[i - 1][j - 1];
        }
    }
    return lookup[m][n];
}
string s;
int count_flips(string a,string b)
{
    int cnt = 0;
    for(int i = 0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            cnt++;
    }
    return cnt;
}
int count_subs(string k)
{

    int cnt = 0;
    string a = "10";
    for(int i = 0;i<k.length()/2;i++)
    {
        cnt+=count(k,a);
        a+="10";
    }
    //cout<<k<<" ---- "<<cnt<<endl;
    return cnt;
}
unordered_map<int,map<string,int>> dp;
int answer(int i, string k)
{
    //cout<<i<<" -- "<<k<<endl;
    if(i==s.length())
    {
        if(count_subs(k) == x)
        {
            return count_flips(k,s);
        }
        return INF;
    }
    if(dp[i].count(k)>0)
        return dp[i][k];
    int temp = answer(i+1,k+"0");
    if(i+1!=s.length())
        temp = min(answer(i+1,k+"1"),temp);
    dp[i][k] = temp;
    return temp;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        dp.clear();
		cin>>s;
		cin>>x;
		string k="1";
        int flips = answer(1,k);
        if(flips<INF)
            cout<<"YES\n"<<flips<<"\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
