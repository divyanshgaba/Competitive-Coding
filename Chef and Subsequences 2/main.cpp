/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<double> vi;
typedef pair<int,int> pi;

void all(int i,double sum,vi a,set<double> &s)
{
    s.insert(sum);
    if(i == a.size())
    {
        return;
    }
    all(i+1,sum,a,s),all(i+1,sum+a[i],a,s);

}

void solve()
{
    int n;
    double k;
    cin>>n>>k;
    k = log2(k);
    cout<<k<<endl;
    double a[n];
    for(int i = 0;i<n;i++) cin>>a[i], a[i] = log2(a[i]);
    vi b,c;
    for(int i = 0;i<n/2;i++) b.PB((a[i]));
    for(int i = n/2;i<n;i++) c.PB((a[i]));
    set<double> sb,sc;
    all(0,0,b,sb),all(0,0,c,sc);
    for(auto i:sb)
        cout<<i<<" ";
    cout<<endl;
    for(auto j:sc)
        cout<<j<<" ";
    cout<<endl;
    int ans = 0;
    for(auto i:sb)
        if(i<=k)
            ans++;
    for(auto i:sc)
        if(i<=k)
            ans++;
    for(auto i:sb)
    {
        for(auto j:sc)
        {
            if(j+i <=k)
                ans++;
        }
    }
    cout<<ans<<endl;

}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
