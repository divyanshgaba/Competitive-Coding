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
const int N = 1e5;
int a[N];
int n;
unordered_map<int,bool> m[N];
bool ans(int i,int sum)
{
    if(sum==0)
        return true;
    if(i==n||sum<0 )
        return false;
    if(m[i].count(sum)>0)
        return m[i][sum];
    bool t = false;
    if(a[i]!=0)
        t |= ans(i,sum-a[i]);
    t |= ans(i+1,sum);
    return m[i][sum] = t;

}

int main()
{
	fast;
	cin>>n;
	int x,y;
	cin>>x>>y;
	for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    int sum = y-x;
    if(ans(0,sum))
        cout<<"POSSIBLE\n";
    else
        cout<<"IMPOSSIBLE\n";
	return 0;

}
