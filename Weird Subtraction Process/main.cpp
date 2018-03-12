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
	ll a,b;
	cin>>a>>b;
	ll lasta=-1,lastb=-1;
	while(lasta!=a || lastb!=b){
        lasta = a;
        lastb = b;
        if(b)
            a%=2*b;
        if(a)
            b%=2*a;
	}
	cout<<a<<" "<<b<<endl;
	return 0;

}
