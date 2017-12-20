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
const int N = 2e5;
int r[N];
vector<int> adj[N];

std::vector<std::string> SortByZ(std::vector<std::string> g, int z) {
    vector<pair<char, pair<int,string> > > v;
    for(int i = 0;i<g.size();i++)
        v.push_back( make_pair(g[i][z-1], make_pair(i,g[i]) ) ) ;
    sort(v.begin(),v.end(),[ ]( const auto& lhs, const auto& rhs )
    {
        if(lhs.first!=rhs.first)
       return lhs.first < rhs.first;
       return lhs.second.first>rhs.second.first;
    });
    vector<string> ans;
    for(auto i:v)
        ans.push_back(i.second);
    return ans;
}

int main()
{
	fast;
	vector<string> v;
	v.PB(string("Rabbit"));
	v.PB(string("Deer"));
	v.PB(string("Chicken"));
	v.PB(string("Cow"));
	auto k = SortByZ(v,3);
	for(auto i:k)
        cout<<i<<" ";
	return 0;

}
