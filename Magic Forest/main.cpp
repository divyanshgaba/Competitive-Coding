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
bool valid(int a, int b, int c)
{
    // check condition
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;
    else
        return true;
}
bool vis[2501][2501];
int main()
{
	fast;
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1;i<=n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            //if(i==j)                continue;

            if(!vis[i][j]&&valid(i,j,i^j)&&((i^j)<=n && ((i^j)>=j)))
                ans++,vis[i][j]=vis[j][i]=true;//,cout<<i<<" "<<j<<endl;
        }
    }
    cout<<ans<<endl;
	return 0;

}
