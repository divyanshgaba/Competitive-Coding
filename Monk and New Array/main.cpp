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

array<array<int,1001>,1001> a;
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }
        sort(a[i].begin(),a[i].begin()+m);
    }
    int ans = 1e9;
    for(int i =0;i<n-1;i++)
    {
        for(int j =0;j<m;j++)
        {
            int elem = a[i][j];
            int dif;
            int ind = lower_bound(a[i+1].begin(),a[i+1].begin()+m,elem) - a[i+1].begin();
            if(ind==0||ind == m-1)
            {
                dif = abs(elem - a[i+1][ind]);
            }
            else
            {
                dif = min(abs(elem-a[i+1][ind]),abs(elem-a[i+1][ind-1]));
            }
            ans = min(ans,dif);
        }
    }
    cout<<ans<<"\n";
	return 0;

}
