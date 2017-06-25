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
    int n,q;
    cin>>n>>q;
    map<int,int> mp;
    while(n--)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    auto i = mp.begin();
    auto j = i;
    for(j++;j!=mp.end();i++,j++)
    {
        mp[j->F] += i->S;
    }
    //for(auto x :mp)        cout<<x.F<<" "<<x.S<<endl;
    map<int,int> revmp;
    for(auto x:mp)
    {
        revmp[x.S] = x.F;
    }
    for(auto x :revmp)
        cout<<x.F<<" "<<x.S<<endl;
    while(q--)
    {
        int k;
        cin>>k;
        auto x = revmp.lower_bound(k);
        cout<<x->S<<endl;
    }
	return 0;

}
