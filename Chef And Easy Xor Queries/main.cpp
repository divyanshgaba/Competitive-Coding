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
const int rtN = 800;
int n;
unordered_map<int,int> m[rtN];
int bucket[rtN][rtN];
int dp[rtN][rtN];
void print()
{
    cout<<"========\n";
    for(int i = 0;i<rtN;i++)
    {
        for(int j = 0;j<rtN;j++)
        {
            cout<<bucket[i][j]<<" ";//=dp[i][j-1]^bucket[i][j-1];
        }
        cout<<endl;
    }
    cout<<"----------\n";
    for(int i = 0;i<rtN;i++)
    {
        for(int j = 0;j<rtN;j++)
        {
            cout<<dp[i][j]<<" ";//=dp[i][j-1]^bucket[i][j-1];
        }
        cout<<endl;
    }
    cout<<"!!!!!!!!!!!!!\n";
}
int main()
{
	fast;
	int q;
	cin>>n>>q;
	//cout<<rtN<<endl;
	int a[n];
	int j = 0;
	for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        bucket[i/rtN][i%rtN] = a[i];
    }
    for(int i = 0;i<n/rtN;i++)
    {
        dp[i][0] = bucket[i][0];
        m[i][dp[i][0]]++;
        for(int j = 1;j<rtN;j++)
        {
            dp[i][j]=dp[i][j-1]^bucket[i][j];
            m[i][dp[i][j]]++;
        }
    }
    dp[n/rtN][0] = bucket[n/rtN][0];
    m[n/rtN][dp[n/rtN][0]]++;
    for(int j = 1;j<n%rtN;j++)
    {
        dp[n/rtN][j]=dp[n/rtN][j-1]^bucket[n/rtN][j];
        m[n/rtN][dp[n/rtN][j]]++;
    }
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int i,x;
            cin>>i>>x;
            i--;
            bucket[i/rtN][i%rtN] = x;
            m[i/rtN].clear();
            for(int j = 0;j<rtN;j++)
            {
                if((floor(i/rtN)*rtN + j) >= n)
                {
                    break;
                }
                if(j==0)
                    dp[i/rtN][j]=bucket[i/rtN][j];
                else
                    dp[i/rtN][j]=dp[i/rtN][j-1]^bucket[i/rtN][j];
                m[i/rtN][dp[i/rtN][j]]++;
            }
        }
        else
        {
            int i,k;
            cin>>i>>k;
            i--;
            int prev = 0;
            int ans = 0;
            for(int j = 0;j<i/rtN;j++)
                ans+=m[j][prev^k],prev^=dp[j][rtN-1];
            for(int j = 0;j<=i%rtN;j++)
                if(dp[i/rtN][j]==(prev^k))
                    ans++;
            cout<<ans<<endl;

        }
    }

	return 0;

}

