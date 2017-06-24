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
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        ll a[n],b[n],d[n];
        long double cost = 0;
        for(int i = 0;i<n;i++)
        {
            long double a,b,d;
            cin>>a>>b>>d;
            if(b<=d)
                continue;
            cost += min((b-d)/a,b/a);
        }
        cout<<fixed<<setprecision(2)<<cost<<endl;

    }
	return 0;

}
