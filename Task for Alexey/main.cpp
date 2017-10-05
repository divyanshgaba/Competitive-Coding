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


ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        ll s[n];
        for(int i = 0;i<n;i++) cin>>s[i];
        ll freeze = 1e18;
		for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                freeze = min(freeze,(s[i]*s[j])/gcd(s[i],s[j]));
            }
        }
        cout<<freeze<<endl;
    }
	return 0;

}
