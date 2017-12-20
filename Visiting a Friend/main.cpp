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

int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	vector<pi> v;
	pi a;
	for(int i = 0;i<n;i++)
        cin>>a.F>>a.S,v.PB(a);
    sort(v.begin(),v.end());
    bool ans = false;
    int cur = 0;
    //cout<<cur<<endl;
    for(auto i:v)
    {
        if(cur>=i.F)
        {
            cur = max(i.S,cur);
        }
        //cout<<cur<<endl;
    }
    if(m>=v[0].F && m<=cur)
        cout<<"YES\n";
    else
        cout<<"NO\n";
	return 0;

}
