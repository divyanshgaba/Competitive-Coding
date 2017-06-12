#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const ll INF = 1e9;
int done[2502][2502];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(done,0,sizeof(done));
        int n,k;
        cin>>n>>k;
        int l[n];
        set<int> base;
        vector<int> v[n],h[k+1],z[n];
        for(int i =0;i<n;i++)
        {
            cin>>l[i];
            for(int j =0;j<l[i];j++)
            {
                int x;
                cin>>x;
                base.insert(base.begin(),x);
                v[i].PB(x);
                h[x].PB(i);
                done[i][x]=1;
            }
            for(int j =1;j<=k;j++)
            {
                if(done[i][j])continue;
                z[i].PB(j);
            }
        }
        if(base.size() != k)
        {
            cout<<0<<endl;
            continue;
        }
        ll ans = 0;
        for(int i =0;i<n;i++)
        {
            if(l[i] == k)
            {
                ans+=(n-1);
                continue;
            }
            vi tmp;
            tmp = h[z[i][0]];
            for(auto it = z[i].begin() + 1;it!=z[i].end();it++)
            {
                auto cut = set_intersection(h[*it].begin(),h[*it].end(),tmp.begin(),tmp.end(),tmp.begin()) - tmp.begin();
                tmp.resize(cut);
            }
            ans+=(tmp.size());
        }
        ans/=2;


        cout<<ans<<endl;

    }
	return 0;

}
