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

set<int> s;
int n,a,b;
map<pi,bool> vis;
void answer(int i,int p)
{
    if(i==n)
    {
        s.insert(p);
        return;
    }
    if(vis[MP(i,p)])
        return;
    vis[MP(i,p)]=true;
    answer(i+1,p+a),answer(i+1,p+b);
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        s.clear();
        vis.clear();
		cin>>n>>a>>b;
		answer(1,0);
		for(auto i:s)
            cout<<i<<" ";
        cout<<endl;
    }
	return 0;

}
