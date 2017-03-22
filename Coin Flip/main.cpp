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
	int test;
    cin>>test;
    while(test--)
    {
        int g;
        cin>>g;
        int i,n,q;
        for(int j =0;j<g;j++)
        {
            cin>>i>>n>>q;
            if(i==q)
                cout<<n/2<<"\n";
            else
            {
                cout<<n/2+n%2<<"\n";
            }
        }
    }
	return 0;

}
