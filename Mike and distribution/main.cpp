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

vi p;
bool mark[100005];
ll sa=0,sb=0;
bool got;
int n;
ll a[100005];
ll b[100005];
void solve(ll ta,ll tb,int i,int k)
{
    if(got)
        return;
    if(ta> sa && tb >sb)
    {
        got = true;
        for(int i =0;i<n;i++)
            if(mark[i])
                p.PB(i+1);
    }
    if(i==n||k==0)
        return;
    mark[i]=true;
    solve(ta+2*a[i],tb+2*b[i],i+1,k-1);
    mark[i]=false;
    solve(ta,tb,i+1,k);

}

int main()
{
	fast;
	cin>>n;
	for(int i =0;i<n;i++)
        cin>>a[i],sa=sa+a[i];
    for(int i =0;i<n;i++)
        cin>>b[i],sb=sb+b[i];
    solve(0,0,0,n/2+1);
    cout<<sa<<" "<<sb<<endl;
    cout<<p.size()<<endl;
    for(auto i:p)
        cout<<i<<" ";
	return 0;

}
