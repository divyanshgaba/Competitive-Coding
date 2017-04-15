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

int ans(int s)
{
    int t=0;
    for(int i =1;i<=sqrt(s);i++)
    {
        t+=(s/i -i+1);
    }
    return t;

}

int main()
{
    fast;
    int test;
    cin>>test;
    while(test--)
    {
        int s;
        cin>>s;
        if(s==1)
            cout<<1<<endl;
        else if(s<9)
            cout<<s+s/2 -1<<endl;
        else
            cout<<ans(s)<<endl;

    }
	return 0;

}
