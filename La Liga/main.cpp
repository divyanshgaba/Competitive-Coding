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
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        int b,e,r,m;
        for(int i =0;i<4;i++)
        {
            cin>>s;
            if(s[0]=='B')
                cin>>b;
            else if(s[0] == 'R')
                cin>>r;
            else if(s[0]=='M')
                cin>>m;
            else
                cin>>e;

        }
        if(r < m && b > e)
            {
                cout<<"Barcelona\n";

            }
            else
                cout<<"RealMadrid\n";

    }
	return 0;

}
