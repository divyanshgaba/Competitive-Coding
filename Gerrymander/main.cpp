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
const int N = 1e6;

int rep[3*N];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(rep,0,sizeof(rep));
        int o1,o2;
        cin>>o1>>o2;
        int n = o1*o2;
        int a[3*n];
        for(int i =n;i<2*n;i++)
        {
            cin>>a[i];
            a[i-n]=a[i+n]=a[i];
            //cout<<a[i]<<" ";
        }
        int sum[3*n];
        sum[0]=a[0];
        for(int i =1;i<3*n;i++)
        {
            sum[i]=sum[i-1]+a[i];
            //cout<<sum[i]<<" ";
        }
        int ans = 0;
        for(int i =n;i<2*n;i++)
        {
            if((sum[i+o2-1]-sum[i-1])>o2/2)
                rep[i] = rep[i-o2] + 1;
            else
                rep[i] =rep[i-o2];
            ans = max(ans,rep[i]);
            //cout<<ans<<" "<<rep[i]<<endl;
        }
        if(ans>o1/2)
            cout<<1<<endl;
        else
            cout<<0<<endl;

    }
	return 0;

}
