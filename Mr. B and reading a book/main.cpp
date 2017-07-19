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

void solve()
{
    int c,v0,v1,a,l;
    cin>>c>>v0>>v1>>a>>l;
    int read = v0;
    int cnt = 1;
    while(read < c)
    {
        int pages_read = min(v0 + cnt*a,v1);
        read += (pages_read-l);
        cnt++;
    }
    cout<<cnt<<endl;
}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
