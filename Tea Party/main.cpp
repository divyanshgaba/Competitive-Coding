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


int main()
{
	fast;
	int n,w;
	cin>>n>>w;
	int req =0;
	int a[n],ans[n];
    priority_queue<pi> q;
	for(int i =0;i<n;i++)
        cin>>a[i],req+=(a[i]/2 + a[i]%2),q.push(MP(a[i],i)),ans[i]= a[i]/2 + a[i]%2;
    if(req>w)
    {
        cout<<-1<<endl;
        return 0;
    }
    w-=req;
    //cout<<w<<endl;
    while(w)
    {
        auto top = q.top();
        q.pop();
        //cout<<top.F<<endl;
        int i = top.S;
        if(w >= (a[i]-ans[i]) )
        {
            w-=(a[i]-ans[i]);
            ans[i]=a[i];
        }
        else
        {
            ans[i]+=w;
            w=0;
        }
    }

    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
	return 0;

}
