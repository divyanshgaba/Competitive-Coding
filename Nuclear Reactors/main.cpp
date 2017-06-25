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
	ll a,n,k;
	cin>>a>>n>>k;
	ll c[k];
	ll prev = a;
	for(int i = 0;i<k;i++)
    {
        c[i] = prev%(n+1);
        prev = prev/(n+1);
    }
    for(int i = 0;i<k;i++)
        cout<<c[i]<<" ";

	return 0;

}
