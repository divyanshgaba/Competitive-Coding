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
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	int shifts = ceil(double(n)/double(k));
	int time1  = shifts*t;
	int until  = ceil(double(d)/double(t));
	if((shifts-until)<=0)
    {
        cout<<"NO\n";
        return 0;
    }
    int time2;
    if((shifts-until)%2 !=0)
    {
        time2 = d + ((shifts-until+1)*t)/2;
    }
    else
    {
        time2 = until*t + ((shifts-until)*t)/2;
    }
    if(time1<=time2)
        cout<<"NO\n";
    else
        cout<<"YES\n";

	return 0;

}
