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
	pi p[4];
	for(int i = 0;i<3;i++)
        cin>>p[i].F>>p[i].S;
    sort(p,p+3);
	cout<<3<<endl;
	cout<<p[0].F + p[2].F - p[1].F <<" "<<p[0].S +p[2].S - p[1].S<<endl;
    cout<<p[0].F + p[1].F - p[2].F <<" "<<p[0].S +p[1].S - p[2].S<<endl;
	cout<<p[1].F + p[2].F - p[0].F <<" "<<p[1].S +p[2].S - p[0].S<<endl;
	return 0;

}
