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

int a[17];

int n;
ll answer(ll val,int i ,int j)
{
    if(i==n)
        return val;
    int ans = val;
    switch(j%3)
        {
        case 0:
            ans|=a[i];
            break;
        case 1:
            ans^=a[i];
            break;
        case 2:
            ans+=a[i];
            break;
        }
    return max(answer(val,i+1,j),answer(ans,i+1,j+1));

}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;

        cin>>n;
        for(int i =0;i<n;i++)
            cin>>a[i];
        ll ans =0;
        for(int i =0;i<n;i++)
        {
            ans = max(ans,answer(a[i],i+1,0));
        }
        //cout<<ans<<endl;
        if((ans&1 && s[0]=='O')||(!(ans&1) && s[0]=='E'))
            cout<<"Monk\n";
        else
            cout<<"Mariam\n";

    }
	return 0;

}
