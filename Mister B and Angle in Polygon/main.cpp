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

void solve()
{
    int n,a;
    cin>>n>>a;
    double angle = ((n-2)*180);
    angle /=double(n);
    double decr = angle/double(n-2);
    double ans = 1e9;
    int ind = 0;
    for(int i = 3;i<=n;i++)
    {
        if(ans > abs(angle - a))
        {
            ans = abs(angle-a);
            ind = i;
        }
        angle -= decr;
    }
    cout<<1<<" "<<2<<" "<<ind<<endl;


}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
