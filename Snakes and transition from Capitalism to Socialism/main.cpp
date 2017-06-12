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

int r[502][502];
int n,m;



int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        cin>>n>>m;
        memset(r,0,sizeof(r));
        int mm = 0;
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                cin>>r[i][j];
                mm = max(r[i][j],mm);
            }
        }
        int time=0;
        stack<pi> l;
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                if(mm == r[i][j])
                    l.push(MP(i,j));
            }
        }
        while(!l.empty())
        {
            stack<pi> k;
            while(!l.empty())
            {
                auto x =l.top();
                l.pop();
                for(int i =x.F-1;i<=x.F+1;i++)
                {
                    for(int j =x.S-1;j<=x.S+1;j++)
                    {
                        if(i<1 || i>n || j<1 || j>m)
                            continue;
                        if(r[i][j] < r[x.F][x.S])
                        {
                            r[i][j] = r[x.F][x.S];
                            k.push(MP(i,j));
                        }
                    }
                }
            }
            while(!k.empty())
            {
                l.push(k.top());
                k.pop();
            }
            time++;
        }
        cout<<time-1<<"\n";


    }
	return 0;

}
