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
	int test;
	cin>>test;
	while(test--)
    {
        ll n;
        cin>>n;;
        ll a[n];
        priority_queue<int,vector<int>,greater<int> > q;
        ll cmp =0;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            q.push(a[i]);
            cout<<q.top();
        }
        ll sum=0;
        while(q.size()>1)
        {
            ll x = q.top();
            q.pop();
            ll y = q.top();
            q.pop();
            sum+=(x+y-1);
            q.push(x+y);
        }
        cout<<sum<<endl;


    }
	return 0;

}
