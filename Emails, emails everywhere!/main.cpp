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

struct cmp {
    bool operator()(pair<int, pair<int,string> >  a,
                              pair<int, pair<int, string> >  b)
    { if(a.F != b.F)
        return a.F < b.F;
    return a.S.F > b.S.F;
    }
};

int main()
{
	fast;
	int n;
	cin>>n;
	priority_queue<pair<int, pair<int,string> > ,vector<pair<int, pair<int, string> > >, cmp > pq;
	for(int i =0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s[0]=='s')
        {
            string x;
            int k;
            cin>>x>>k;
            pq.push(MP(k,MP(i,x)));
        }
        else
        {
            if(!pq.empty())
            {
                cout<<pq.top().S.S<<endl;
                pq.pop();
            }
            else
            {
                cout<<-1<<endl;
            }
        }
    }
	return 0;

}
