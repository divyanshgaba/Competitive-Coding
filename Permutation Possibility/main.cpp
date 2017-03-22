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

int s[100001];
int main()
{
	fast;
	int test;
    int m;
    cin>>m;
    bool poss=true;
    for(int i =0;i<m;i++)
    {
        int x;
        cin>>x;
        if(s[x]==0)
        {
            s[x]=1;
            continue;
        }
        else if(s[x]==1)
        {
            poss = false;
            continue;
        }
    }
    if(poss)
        cout<<"YES\n";
    else
        cout<<"NO\n";
	return 0;

}
