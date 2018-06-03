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
	int l,r,a;
	cin>>l>>r>>a;
	int ans = 0;
	ans = min(l,r);
	l-=ans,r-=ans;
	l=r=max(l,r);
	int h = min(l,a);
	l-=h,a-=h;
	ans += h;
	ans+=a/2;
	cout<<2*ans<<endl;
	return 0;

}
