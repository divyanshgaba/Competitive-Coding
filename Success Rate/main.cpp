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
        ll x,y,p,q;
        cin>>x>>y>>p>>q;
        ll l = 0,h = y;
        ll k=-1;
        if(p==q)
        {
            if(x==y)
                cout<<0<<endl;
            else
                cout<<-1<<endl;
            continue;
        }
        if(p==0)
        {
            if(x==0)
                cout<<0<<endl;
            else
                cout<<-1<<endl;
            continue;
        }
        while(l<h)
        {
            ll m = (l+h)/2;
            if(m*p>=x && m*(q-p)>=y-x)
            {
                k = m;
                h = m;
            }
            else
            {
                l = m+1;
            }
        }
        //cout<<k<<endl;
        if(k*p>=x && k*(q-p)>=y-x)
            cout<<q*k-y<<endl;
        else
            cout<<-1<<endl;
    }
	return 0;

}
