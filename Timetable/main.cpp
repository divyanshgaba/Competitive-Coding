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

int main()
{
	fast;
	int n,m,k;
	cin>>n>>m>>k;
	char day[n][m];
	vector<int> v[n];
	for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {

            cin>>day[i][j];
            if(day[i][j]=='1')
                v[i].PB(j);
        }
    }
    priority_queue<pi> p;
    for(int i = 0;i<n;i++)
    {
        if(v[i].size()==0)
            continue;
        if(v[i].size()==1)
            p.push(MP(1,i));
        else
        {
            p.push({max(llabs(v[i][0]-v[i][1]),llabs(v[i][v[i].size()-1]-v[i][v[i].size()-2])),i});
        }
    }
    for(int i = 0; i<k;i++)
    {
        if(p.empty())
            break;
        auto t = p.top();
        p.pop();
        if(v[t.S].size()==1)
            v[t.S].pop_back();
        else
        {
            if(llabs(v[t.S][0] - v[t.S][1]) == t.F)
                v[t.S].erase(v[t.S].begin());
            else
                v[t.S].pop_back();
            if(v[i].size()==1)
                p.push(MP(1,i));
            else
            {
                p.push({max(llabs(v[t.S][0]-v[t.S][1]),llabs(v[t.S][v[t.S].size()-1]-v[t.S][v[t.S].size()-2])),t.S});
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(v[i].size()==0)
            continue;
        ans += (v[i][v[i].size()-1] - v[i][0] + 1);
    }
    cout<<ans<<endl;
	return 0;

}
