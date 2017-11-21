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

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		ll a[n];
		ll p[n],s[n];
		for(int i =0;i<n;i++) cin>>a[i];
		p[0]=s[0]=a[0];
		for(int i = 1;i<n;i++) p[i]=p[i-1]*a[i],s[i]=s[i-1]+a[i];
		int ans = 0;
		for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0)
                {
                    if(s[j]==p[j])
                        ans++;
                }
                else
                {
                    if(s[j]-s[i-1]==p[j]/p[i-1])
                        ans++;
                }
            }
        }
        cout<<ans<<endl;

    }
	return 0;

}
