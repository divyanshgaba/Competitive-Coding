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
const int INF = 1e8;
vector<pi> bp[2];
int main()
{
	fast;
	int n,c,d;
	cin>>n>>c>>d;
	for(int i =0;i<n;i++)
    {
        pi t;
        char ch;
        cin>>t.S>>t.F>>ch;
        if(ch-'C')
        {
            if(t.S>d)
                continue;
        }
        else
        {
            if(t.S>c)
                continue;

        }
        bp[ch-'C'].PB(t);
    }
    sort(bp[0].begin(),bp[0].end());
    sort(bp[1].begin(),bp[1].end());

}
