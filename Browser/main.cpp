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
	//cin>>test;
	while(test--)
    {
		int n,pos,l,r;
		cin>>n>>pos>>l>>r;
		if(l>1 && r<n)
        {
            int ans = 2 + min( abs(r-pos) + (r-l), abs(pos-l) + (r-l));
            cout<<ans<<endl;
        }
        else if(r<n)
        {
            int ans = 1 + abs(r-pos);
            cout<<ans<<endl;
        }
        else if(l>1)
        {
            int ans = 1 + abs(pos-l);
            cout<<ans<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
	return 0;

}
