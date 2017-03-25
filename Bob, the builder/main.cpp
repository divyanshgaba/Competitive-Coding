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
typedef pair<ll,ll> pi;


int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        vector<pi> a;
        for(int i =0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(make_pair(x,i+1));
        }
        vector<pi> b;
        copy(a.begin(),a.end(),back_inserter(b));
        vector<pi> c;
        copy(a.begin(),a.end(),back_inserter(c));
        sort(b.begin(),b.end());
        ll costa =0;
        ll i =1;
        for(auto it:b)
        {
            costa+=(abs(it.S-i));
            i++;
        }
        sort(c.begin(),c.end(),greater<pi>());
        i =1;
        ll costb=0;
        for(auto it:c)
        {
            costb+=(abs(it.S-i));
            i++;
        }
        cout<<min(costa,costb)<<endl;

    }
	return 0;

}
