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


int main()
{
	fast;
	int n,m,bx,by;
	cin>>n>>m>>bx>>by;
	pi pillar[n];
	for(int i =0;i<n;i++)
    {
        cin>>pillar[i].F>>pillar[i].S;
    }
    pi seg[m+1];
    for(int i =0;i<=m;i++)
    {
        cin>>seg[i].F>>seg[i].S;

    }
	return 0;

}
