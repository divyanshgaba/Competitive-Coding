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

ll count_one (ll n)
        {
            ll count=0;
            while( n )
            {
            n = n&(n-1);
               count++;
            }
            return count;
    }

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll p;
        cin>>p;
        cout<<count_one(p)<<endl;

    }
	return 0;

}
