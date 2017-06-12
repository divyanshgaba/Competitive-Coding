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
	ll h[n];
	deque<ll> q;
	for(int i =0;i<n;i++)
    {
        cin>>h[i];
    }
    sort(h,h+n);
    ll cur =0;
    int idx = n-1;
    ll last = 1;
    for(int i =0;i<m;i++)
    {
        ll x;
        cin>>x;
        while(cur<x)
        {
            if(q.empty() || (idx>=0 && h[idx] > q.front()))
            {
                last = h[idx--];
            }
            else
            {
                last = q.front();
                q.pop_front();
            }
            cur++;
            if(last != 1)
                q.push_back(last/2);
        }
        cout<<last<<endl;
    }

	return 0;

}

