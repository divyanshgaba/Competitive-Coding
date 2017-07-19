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
	int test=1;
	cin>>test;
	while(test--)
    {
        ll n,b;
        cin>>n>>b;
        ll ans = 0;
        if(n<=b)
        {
            cout<<0<<endl;
            continue;
        }

        ll x = b + (n-b)/2;
        if(x%b==0 || (n-x)%b==0)
            ans = (x*(n-x))/b;
        else
        {
            x = x - x%b;
            ans = (x*(n-x))/b;
        }

        cout<<ans<<endl;


    }
	return 0;

}
