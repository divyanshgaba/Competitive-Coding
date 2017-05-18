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
	int n,hit,t;
	cin>>n>>hit>>t;
	int h[n];
	for(int i =0;i<n;i++)
        cin>>h[i];
    sort(h,h+n);
    int ans =0;
    int i =0;
    while(t>0&&i<n)
    {
        int req = ceil(double(h[i])/double(hit));
        //cout<<req<<endl;
        if(req<=t)
            ans++;
        t-=req;
        i++;
    }
	cout<<ans<<endl;
	return 0;

}
