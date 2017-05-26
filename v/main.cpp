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

ll bit[100001];
int n;
void update(int i,ll v)
{
    for(;i<=n;i+=i&(-i))
        bit[i]+=v;
}

ll sum(int i)
{
    ll ans = 0;
    for(;i>0;i-=i&(-i))
        ans+=bit[i];
    return ans;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int c;
        cin>>n>>c;
        memset(bit,0,sizeof(bit));
        while(c--)
        {
            int x;
            cin>>x;
            if(x==0)
            {
                int p,q;
                cin>>p>>q;
                ll v;
                cin>>v;
                for(int i =p;i<=q;i++)
                {
                    update(i,v);
                }
            }
            else
            {
                int p,q;
                cin>>p>>q;
                cout<<sum(q) -sum(p-1)<<endl;
            }
        }

    }
	return 0;

}
