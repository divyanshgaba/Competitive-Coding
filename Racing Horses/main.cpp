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
        int n;
        cin>>n;
        int s[n+1];
        REP(i,0,n-1)
        {
            cin>>s[i];
        }
        sort(s,s+n);
        int dif = s[n-1] - s[0];
        REP(i,1,n-1)
        {
            if(dif > s[i] -s[i-1])
                dif=s[i]-s[i-1];
        }
        cout<<dif<<"\n";
    }
	return 0;

}

