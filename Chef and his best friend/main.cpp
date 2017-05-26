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
        int a[n];
        int ans =0;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        int j=0;
        for(int i =0;i<n;i++)
        {
            if(a[i]==0)
                j++;
            else
                ans=j;
        }

        cout<<ans<<endl;

    }
	return 0;

}
