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
const int N = 1e4;
vector<int> graph[N];
int n;
void addEdge(int a,int b)
{
    graph[a].PB(b);
    graph[b].PB(a);
}
bool is_bipartite(int s) {
    vector<int> side(n, 0);
    queue<int> q;
    side[s] = 1; // left
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &neighbour : graph[node]) {
            if (!side[neighbour]) {
                side[neighbour] = - side[node];
                q.push(neighbour);
            } else if (side[neighbour] == side[node]) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
	fast;
	cin>>n;
	int cnt = 0;
	unordered_map<int,int> ma;
    int a,b;
    cin>>a>>b;
    if(ma.count(a)==0)
        ma[a]=cnt++;
    if(ma.count(b)==0)
        ma[b]=cnt++;
    addEdge(ma[a],ma[b]);
    while(is_bipartite(a))
    {
        cout<<1<<endl;
        cin>>a>>b;
        if(ma.count(a)==0)
            ma[a]=cnt++;
        if(ma.count(b)==0)
            ma[b]=cnt++;
        addEdge(ma[a],ma[b]);
    }
    cout<<0<<endl;
	return 0;

}
