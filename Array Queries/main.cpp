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


map<pi,int> mp;

int main()
{
	fast;
	int n;
	cin>>n;
	int a[n+1];
	for(int i =1;i<=n;i++)
        cin>>a[i];
    int q;
    cin>>q;
    for(int i =0;i<q;i++)
    {
        int p,k;
        cin>>p>>k;
        int ans = 0;
        if(mp.count(MP(p,k)) >0 )
            ans = mp[MP(p,k)];
        else
        {
            int h=p;
            while(p<=n)
            {
                p+=(a[p]+k);
                ans++;
                if(mp.count(MP(p,k)) >0 )
                {
                    ans+=mp[MP(p,k)];
                    break;
                }
            }
            mp[MP(h,k)] = ans;
        }
        cout<<ans<<endl;

    }


	return 0;

}
