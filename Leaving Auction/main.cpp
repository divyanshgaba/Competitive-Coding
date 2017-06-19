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
const int N = 3e5 + 7;
ll maximum[N];
vector<ll> bids[N];
int main()
{
	fast;
	int n;
	cin>>n;
	pair<ll,ll> a;
	set<pair<ll,ll>,greater<pair<ll,ll> > > man;
	for(int i = 0;i<n;i++)
        cin>>a.F>>a.S,maximum[a.F] = max(maximum[a.F],a.S),bids[a.F].PB(a.S);
    for(int i = 1;i<=n;i++)
        if(maximum[i]!=0)
            man.insert(MP(maximum[i],i));
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        ll t[k];
        for(int i = 0;i<k;i++)
            cin>>t[i],man.erase(MP(maximum[t[i]],t[i]));
        if(man.empty())
            cout<<0<<" "<<0<<endl;
        else
        {
            auto itf = man.begin();

            auto ptf = *itf;
            auto its = man.begin();
            its++;
            if(itf == man.end())
                cout<<0<<" "<<0<<endl;
            else if(its != man.end())
            {
                auto pts = *its;
                cout<<ptf.S<<" "<<(*lower_bound(bids[ptf.S].begin(),bids[ptf.S].end(),pts.F))<<endl;
            }
            else
                cout<<ptf.S<<" "<<bids[ptf.S][0]<<endl;
        }
        for(int i = 0;i<k;i++)
            if(maximum[t[i]]!=0)
                man.insert(MP(maximum[t[i]],t[i]));
    }
	return 0;

}
