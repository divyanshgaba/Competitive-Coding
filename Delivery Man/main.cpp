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
typedef vector<int> vi;
typedef pair<int,int> pi;
const int N = 1e5;
int n;
int a[N];
int b[N];
int main()
{
	fast;
	int x,y;
	cin>>n>>x>>y;
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];
    vector<pair<int,int>> p;
    for(int i = 0;i<n;i++) p.PB({abs(a[i]-b[i]),i});
    sort(p.begin(),p.end(),greater<pair<int,int>>());
    int ans = 0;
    int i = 0;
    while(x>0&&y>0&&i<n)
    {
        auto j = p[i].S;
        if(a[j]<b[j])
            ans+=b[j],y--;
        else
            ans+=a[j],x--;
        i++;
    }
    while(x>0&&i<n)
    {
        auto j = p[i].S;
        ans+=a[j],x--;
        i++;
    }
    while(y>0&&i<n)
    {
        auto j = p[i].S;
        ans+=b[j],y--;
        i++;
    }
    cout<<ans<<endl;
	return 0;

}
