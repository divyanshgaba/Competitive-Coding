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
	ll test;
	cin>>test;
	while(test--)
    {
        ll n;
        cin>>n;
        if(n<=2)
            cout<<n<<endl;
        else
        {
            if(n%2!=0)
            {
                cout<<n*(n-1)*(n-2)<<endl;
            }
            else
            {
                cout<<n*(n-1)*(n-2)/2<<endl;
            }
        }
    }
	return 0;

}
