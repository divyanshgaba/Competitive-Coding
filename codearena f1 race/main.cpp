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

int mem[100002];
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        int a[n+1];
        memset(mem,0,sizeof(mem));
        for(int i =1;i<=n;i++)
            cin>>a[i];
        int ans =0;
        a[0]=0;
        int curspeed = 1e9;
        int temp =0;
        for(int i =1;i<=n;i++)
        {
            if(a[i]<=curspeed)
            {
                temp++;
                curspeed = a[i];
            }
            else
            {
                ans = max(ans,temp);

            }

        }
        ans = max(ans,temp);
                cout<<ans<<endl;
    }
	return 0;

}
