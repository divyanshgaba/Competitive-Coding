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
#define inarr(n,a) for (int i = 0;i<n;i++) cin>>a[i]

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
int b[21];
int mem[21][1001];
bool ans(int i,int m)
{
    if(i == n)
    {
        if(m == 0)
            return true;
        else
            return false;
    }
    if(mem[i][m])
        return mem[i][m]==1?true:false;
    if(m == 0)
        return true;
    if(m<0)
        return false;
    bool t = ans(i+1,m-b[i])||ans(i+1,m);
    if(t)
        mem[i][m]=1;
    else
        mem[i][m]=-1;
    return t;

}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(mem,0,sizeof(mem));
        int m;
        cin>>n>>m;
        inarr(n,b);
        if(ans(0,m))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
	return 0;

}
