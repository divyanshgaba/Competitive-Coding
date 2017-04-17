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

const int INF = -1e9;

int n;
vector<int> a;

int main()
{
	fast;
	cin>>n;
	int ans =0;
	for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x%2==0&& x>0 )
        {
            ans+=x;
        }
        else if(x%2!=0)
        {
            a.PB(x);
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    int len = a.size();
    ans+=a[0];
    for(int i =1;i<len-1;i++)
    {
        if((a[i]+a[i+1]) > 0)
        {
            ans+=(a[i]+a[i+1]);
            i++;
        }
    }
    cout<<ans<<endl;
	return 0;

}
