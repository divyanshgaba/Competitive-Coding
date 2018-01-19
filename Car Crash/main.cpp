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
const ll maxval =1e9;
int main()
{
    //ifstream cin("input/input04.in");
    //ofstream cout("output/output04.out");
	int test=1;
	cin>>test;
	assert(1<=test && test<=100000);
	while(test--)
    {
		ll a,b;
		cin>>a>>b;
		assert(1<=a && a<=maxval);
		assert(1<=b && b<=maxval);
		if(a>=b)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            ll ans = ceil(sqrt(b*b - a*a));
            assert(ans>0);
            cout<<ans<<endl;
        }
    }
	return 0;

}
