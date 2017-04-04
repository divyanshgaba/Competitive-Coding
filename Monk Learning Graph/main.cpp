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

bool mcmp(pi a, pi b)
{
    if(a.F==b.F)
        return a.S>b.S;
    return a.F>b.F;
}

int n,m,k;
int node[1003][1003];
pi val[1003];
int main()
{
	fast;
	cin>>n>>m>>k;
	for(int i =1;i<=n;i++)
    {
        int x;
        cin>>x;
        val[i] = make_pair(x,i);
    }
    for(int i =0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        node[x][y]++;
        node[y][x]++;
    }
    for(int i =1;i<=n;i++)
    {
        vector<pi> v;
        for(int j =1;j<=n;j++)
        {
            //cout<<node[i][j]<<" ";
            for(int z =0;z<node[i][j];z++)
                v.PB(val[j]);
        }
        //cout<<endl;
        sort(v.begin(),v.end(),mcmp);
        if(k-1<v.size())
            cout<<v[k-1].S<<endl;
        else
            cout<<-1<<endl;
    }
	return 0;

}
