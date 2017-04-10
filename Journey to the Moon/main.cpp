#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

vi a[100002];
bool visi[100002];
int nodes;
vi ans;

void dfs(int n)
{
    if(visi[n])
        return;
    nodes++;
    visi[n]=true;
    for(auto it:a[n])
    {
        dfs(it);
    }
}

int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	for(int i =0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].PB(y);
        a[y].PB(x);
    }
    ll way = n*n;
    cout<<way<<endl;
    for(int i =0;i<n;i++)
    {
        if(!visi[i])
        {
            nodes=0;
            dfs(i);
            way-=((nodes*(nodes-1))/2);
        }
    }
    cout<<way<<endl;
	return 0;

}
