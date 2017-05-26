#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
        ll n;
        cin>>n;
        ll c[n];
        for(int i =0;i<n;i++)
            cin>>c[i];
        ll tem = c[0];
        for(int i =1;i<n;i++)
        {
            tem =min(c[i],tem);
            c[i]=tem;
        }
        ll l[n];
        for(int i =0;i<n;i++)
            cin>>l[i];
        ll cost=0;
        for(int i =0;i<n;i++)
        {
            cost+=(c[i]*l[i]);
        }
        cout<<cost<<endl;
    }
	return 0;

}
