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
        int n;
        cin>>n;
        int a[2*n];
        for(int i =0;i<2*n;i++)
            cin>>a[i];
        sort(a,a+2*n);
        int ans = a[n + n/2];
        cout<<ans<<endl;
        for(int i =0;i<n;i++)
        {
            cout<<a[i]<<" "<<a[2*n-i-1]<<" ";
        }
        cout<<endl;
    }
	return 0;

}
