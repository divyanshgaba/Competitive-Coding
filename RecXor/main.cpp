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

ll computeXor(ll n)
{
    if (n % 4LL == 0)
        return n;
    if (n % 4LL == 1LL)
        return 1;
    if (n % 4LL == 2LL)
        return n + 1;
   return 0;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        ll l,h,n,d1,d2;
        cin>>l>>h>>n>>d1>>d2;
        ll x = computeXor(l*h+n-1) ^ computeXor(n-1);
        ll i1 = (d1-1)/l;
        ll j1 = (d1-1)%l;
        j1-=(n-1);
        while(j1<0)
            j1+=l,i1-=1;
        ll i2 = (d2-1)/l;
        ll j2 = (d2-1)%l;
        j2-=(n-1);
        while(j2<0)
            j2+=l,i2-=1;
        pair<ll,ll> left = MP(min(i1,i2),min(j1,j2));
        pair<ll,ll> right = MP(max(i1,i2),max(j1,j2));
        //cout<<left.F<<" "<<left.S<<endl;
        //cout<<right.F<<" "<<right.S<<endl;
        for(ll i = left.F;i<=right.F;i++)
        {
            ll temp = computeXor((i)*l + right.S + n)^computeXor((i)*l + left.S+n-1);
            x^=temp;
        }
        cout<<x<<endl;


    }
	return 0;

}
