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

int bit[32];

bool cmp(pi a, pi b)
{
    if(a.F == b.F)
        return a.S < b.S;
    else
        return a.F > b.F;
    return false;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(bit,0,sizeof(bit));
        int n;
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        //int tmp = 1;
        pi ans = {0,0};
        for(int i =0;i<32;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(a[j]&(1<<i))
                    bit[i]++;
            }
            if(bit[i] > ans.F)
                ans.F =bit[i],ans.S=i;
        }
        //for(int i =0;i<32;i++)            cout<<bit[i]<<" ";        cout<<endl;
        cout<<ans.S<<endl;



    }
	return 0;

}
