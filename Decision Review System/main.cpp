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
        double ov,t=0;
        int f[10],j=1;
        memset(f,0,sizeof(f));
        for(int i =0;i<n;i++)
        {
            cin>>ov;
            while(ov > j*80)
            {
                j++;
            }
            f[j-1]++;
        }
        int ans=0;
        for(int i =0;i<j;i++)
        {
            ans+=(min(2,f[i]));
        }
        cout<<ans<<endl;


    }
	return 0;

}
