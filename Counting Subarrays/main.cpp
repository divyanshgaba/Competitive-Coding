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

ll mem[100005];

int main()
{
	fast;
	int test;
	cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        ll a[n+1];
        memset(mem,0,sizeof(mem));
        ll sum =0;
        for(int i =1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]>=a[i-1])
                mem[i]=mem[i-1]+1;
            else
                mem[i]=1;
        }

        for(int i =1;i<=n;i++)
            sum+=mem[i];
        cout<<sum<<endl;
    }
	return 0;

}
