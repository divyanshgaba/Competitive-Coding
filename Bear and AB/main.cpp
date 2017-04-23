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

ll fact(ll n)
{
    if(n<=0)
        return 1;
    return fact(n-1)*n;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        //cout<<ans<<endl;
        ll a =0;
        ll temp =0;
        int mem[n+2];
        memset(mem,0,sizeof(mem));
        for(int i =n-1;i>=0;i--)
        {
            mem[i]=mem[i+1];
            if(s[i] =='b')
                mem[i]+=1;
        }
        ll init =0;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='a')
            {
                a++;
                init+=mem[i];
            }
        }
        cout<<init*k + (a*(k-1)*k*mem[0])/2<<endl;
        /*for(int i =0;i<n;i++)
            cout<<mem[i]<<" ";*/

    }
	return 0;

}
