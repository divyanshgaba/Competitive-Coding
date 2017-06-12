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
ll s[100001];
ll greedy(ll n, ll l, ll x,ll m)
{

    ll i = x-1,j = x;
    ll cost=0;
    ll posx = m-l;
    while(i>=0)
    {
        cost += (abs(s[i--] - posx));
        posx-=l;
    }
    while(j<n)
    {
        cost += (abs(s[j++] - m));
        m+=l;
    }
    return cost;

}


int main()
{
	//fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll n,l,a,b;
        cin>>n>>l>>a>>b;
        for(int i =0;i<n;i++)
            cin>>s[i];
        sort(s,s+n);
        ll lo = a,hi = b;
        auto temp = greedy(n,l,0,a);
        ll cost = temp.F+temp.S;
        while(lo<=hi)
        {
            ll mid = lo + (hi-lo)/2;
            ll x = lower_bound(s,s+n,mid) - s;
            //cout<<x<<" "<<mid<<endl;
            //cout<<lo<<" "<<mid<<" "<<hi<<endl;
            if(mid + (n-x)*l > b)
            {
                hi = mid - 1;
                continue;
            }
            if(a + x*l > mid)
            {
                lo = mid + 1;
                continue;
            }
            ll subcost = greedy(n,l,x,mid);
            cost = min(cost, subcost);
            ll X = greedy(n,l,x,mid+1),Y =greedy(n,l,x,mid-1);
            if(X <Y)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
            //cout<<cost<<" "<<subcost.F<<" "<<subcost.S<<endl;
        }
        cout<<cost<<endl;
    }
	return 0;

}
