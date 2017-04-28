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

int n,k;
int a[100001];
int p[100001];
vector<int> adj[100001];
bool visited[100001];

int solve(int i ,int x)
{
    int temp =0;
    x^=a[i];
    if(!x^k)
        temp =1;


}

int main()
{
	fast;
	cin>>n>>k;
	for(int i =1;i<=n;i++)
        cin>>a[i];
    for(int i =2;i<=n;i++)
        cin>>p[i],adj[p[i]].PB(i);
    cout<<solve(1,0)<<endl;

	return 0;

}
