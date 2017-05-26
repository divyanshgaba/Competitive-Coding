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

bool bought[2000001];

int main()
{
	fast;
	int n;
	cin>>n;
	int p[n];
	for(int i =0;i<n;i++)
        cin>>p[i];
	int a[n],b[n];
	for(int i =0;i<n;i++)
        cin>>a[i];
    for(int i =0;i<n;i++)
        cin>>b[i];
    priority_queue<pi,vector<pi>,greater<pi> > c[4];
    for(int i =0;i<n;i++)
    {
        c[a[i]].push(MP(p[i],i));
        c[b[i]].push(MP(p[i],i));
    }
    int m;
    cin>>m;
    while(m--)
    {
        int k;
        cin>>k;
        if(c[k].empty())
        {
            cout<<-1<<" ";
            continue;
        }
        while(bought[(c[k].top()).S])
        {
            c[k].pop();
            if(c[k].empty())
                break;
        }
        if(c[k].empty())
        {
            cout<<-1<<" ";
            continue;
        }
        cout<<c[k].top().F<<" ";
        bought[c[k].top().S] =true;
        c[k].pop();
    }
    cout<<endl;
	return 0;

}
