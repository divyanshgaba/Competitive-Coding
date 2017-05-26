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
        vector<int> h(n);
        for(int i =0;i<n;i++)
        {
            cin>>h[i];
        }
        ll ans=0;
        for(int i =0;i<n;i++)
        {
            int t =h[i];
            ll cnt = 0;
            int j;
            for(j =i;j<n;j++)
            {
                if(t == h[j])
                    cnt++;
                else
                    break;
            }
            ans+=((cnt*(cnt+1))/2);
            i = j-1;
        }
        cout<<ans<<endl;
    }
	return 0;

}
