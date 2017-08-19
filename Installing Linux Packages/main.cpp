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

map<string, int> code;
map<int, string> name;
const int N = 1e5;
vector<int> adj[N];
stack<int> st;
bool visited[N];

void dfs(int v)
{
    visited[v] =true;
    for(auto i: adj[v])
    {
        if(!visited[i])
            dfs(i);
    }
    st.push(v);
}
void topo(int n)
{
    for(int i = 0;i<n;i++)
        if(!visited[i])
            dfs(i);
    while(!st.empty())
    {
        cout<<name[st.top()]<<" ";
        st.pop();
        if(!st.empty())
        {
            cout<<"-> ";
        }
    }
    cout<<endl;
}
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	int cnt = 0;
	for(int i = 0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;
        if(code.count(a) == 0)
            code[a] = cnt++,name[code[a]] = a;
        if(code.count(b) == 0)
            code[b] = cnt++,name[code[b]] = b;
        adj[code[a]].PB(code[b]);
    }
    topo(n);
	return 0;

}
