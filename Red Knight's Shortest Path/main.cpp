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
int dx[]={-2,-2,+0,+2,+2,+0};
int dy[]={-1,+1,+2,+1,-1,-2};
string s[]={"UL","UR","R","LR","LL","L"};
const int moves = 6;
const int N = 201;
const int INF = 1e9;
int n;
bool valid(int x,int y)
{
    if(x<0||y<0||x>=n||y>=n)
        return false;
    return true;
}
pi st,en;
int parent[N][N];
vector<vector<int>> dist(N,vector<int>(N,INF));
int bfs(int x,int y)
{
    memset(parent,~0,sizeof(parent));
    dist[x][y]=0;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>>> p;
    p.push({0,{x,y}});
    while(!p.empty())
    {
        auto u = p.top();
        p.pop();
        if(vis[u.S.F][u.S.S])
            continue;
        vis[u.S.F][u.S.S]=true;
        for(int i = 0;i<moves;i++)
        {
            int xi = u.S.F+dx[i];
            int yi = u.S.S+dy[i];
            if(!valid(xi,yi))
                continue;
            if(dist[xi][yi]>=dist[u.S.F][u.S.S]+1&&parent[xi][yi]<i)
                dist[xi][yi]=dist[u.S.F][u.S.S]+1,parent[xi][yi]=i,p.push({dist[xi][yi],{xi,yi}});//cout<<xi<<" "<<yi<<" "<<dist[xi][yi]<<endl;
        }
    }
    return dist[en.F][en.S];
}
int main()
{
	fast;
	cin>>n;
    cin>>st.F>>st.S;
    cin>>en.F>>en.S;
    int ans = bfs(st.F,st.S);

    if(ans!=INF)
    {
        cout<<ans<<endl;
        stack<int> st;
        int x = en.F,y=en.S;
        while(parent[x][y]!=-1)
        {
            int i = parent[x][y];
            x = x-dx[i];
            y = y-dy[i];
            st.push(i);
        }
        while(!st.empty())
            cout<<s[st.top()]<<" ",st.pop();
        cout<<endl;


    }
    else
        cout<<"Impossible\n";
	return 0;

}
