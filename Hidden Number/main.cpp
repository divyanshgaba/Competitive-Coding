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

int mem[100001];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        memset(mem,0,sizeof(mem));
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            int x;
            cin>>x;
            ans^=x;
            if(mem[x]==0)
            {
                mem[x]=1;
            }
            else if(mem[x]==1)
            {
                mem[x]=2;
                ans^=x;
            }
        }
        cout<<ans<<endl;
    }
	return 0;

}
