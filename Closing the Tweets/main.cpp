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

int a[1001];
int ans;
int main()
{
	fast;
	int n,k;
	cin>>n>>k;
	for(int i =0;i<k;i++)
    {
        string s;
        int x;
        cin>>s;
        if(s[2]=='O')
        {
            memset(a,0,sizeof(a));
            ans =0;
        }
        else
        {
            cin>>x;
            if(a[x]==1)
            {
                a[x]=0;
                ans--;
            }
            else
            {
                a[x]=1;
                ans++;
            }
        }
        cout<<ans<<endl;
    }

	return 0;

}
