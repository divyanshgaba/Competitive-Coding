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
const int N =50001;

int n;
int t[2*N];

int main()
{
	fast;
	cin>>n;
	for(int i =0;i<n;i++)
        cin>>t[n+ i].F,t[n+i].S=0;
    build();
    int m;
    cin>>m;
    while(m--)
    {
        int k,x,y;
        cin>>k>>x>>y;
        if(k==0)
        {
            modify(x-1,y);
        }
        else
        {
            cout<<query(x-1,y)<<endl;
        }
    }
	return 0;

}
