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
        cin>>n;;
        ll a[n];
        ll cmp =0;
        for(int i =0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        ll sum=0;
        for(int i =0;i<n-1;i++)
        {
            sum+=(a[i]+a[i+1]-1);
            a[i+1]+=a[i];
        }
        cout<<sum<<endl;


    }
	return 0;

}
