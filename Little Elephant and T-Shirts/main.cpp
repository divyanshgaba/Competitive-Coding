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
const string delim = " ";
const int mod = 1e9+7;
bool has[10][101];
int n;
int dp[1025][101];
int answer(int mask,int tid)
{
    if(mask == pow(2,n) - 1)
        return dp[mask][tid] = 1;
    if(tid == 101)
        return 0;
    if(dp[mask][tid]!=-1)
        return dp[mask][tid];
    int ans = 0;
    ans =(ans +  answer(mask,tid+1))%mod;
    for(int i = 0;i<n;i++)
    {
        if(mask&(1<<i))
            continue;
        if(!has[i][tid])
            continue;
        ans =(ans+ answer(mask|(1<<i),tid+1))%mod;
    }
    return dp[mask][tid] = ans;

}

int main()
{
    fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        memset(has,false,sizeof(has));
        memset(dp,~0,sizeof(dp));
		cin>>n;
		for(int i = 0;i<n;i++)
        {
            string s;
            getline(cin,s);
            if(s.length() == 0)
            {
                i--;
                continue;
            }
            int pos = 0;
            while((pos = s.find(delim))!=s.npos)
            {
                string token = s.substr(0,pos);
                has[i][(stoi(token))]=true;
                s.erase(0,pos + delim.length());
            }
            has[i][(stoi(s))]=true;
        }
        cout<<answer(0,1)<<endl;

    }
	return 0;

}
