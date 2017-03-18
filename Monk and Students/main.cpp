#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > points;

ll GCD(ll a, ll b)
{
	if(b==0)
		return a;
	else
		return GCD(b, a%b);
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first<b.first;
}
bool mcmp(pair<ll,ll> b,const int val)
{
    return b.first<val;
}
int main()
{
    int n;
    cin>>n;
    for(ll i =1;i<=n;i++)
    {
        pair<ll,ll> x,y;
        cin>>x.first>>y.first;
        cin>>x.second>>y.second;
        points.push_back(make_pair(GCD(abs(x.second-x.first),abs(y.second-y.first))+1,i));
        //cout<<GCD(abs(x.second-x.first),abs(y.second-y.first))+1<<endl;
    }
    sort(points.begin(),points.end());
    //for(auto it: points)        cout<<(it).first<<" "<<(it).second<<endl;
    int q;
    cin>>q;
    for(int i =0;i<q;i++)
    {
        int x;
        cin>>x;
        int ind = lower_bound(points.begin(),points.end(),x,mcmp)-points.begin();
        if(x>points[ind].first)
            cout<<"-1"<<endl;
        else
            cout<<points[ind].second<<endl;

    }
    return 0;
}
