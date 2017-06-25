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
const int N = 1e6+1;


int main()
{
	//fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll n;
        cin>>n;
        ll c[n],w[n],sum[n];
        for(ll i = 0;i<n;i++)
            cin>>c[i];
        for(ll i  = 0;i<n;i++)
            cin>>w[i];
        sum[0]=w[0];
        for(ll i = 1;i<n;i++)
            sum[i] = sum[i-1] +  w[i];
        int l = 0,r=0;
        bool mp[n];
        memset(mp,false,sizeof(mp));
        ll ans = 0,temp=0;
        bool gotit = true;
        for(;;)
        {
            while (r<n && !mp[c[r]])
            {
                temp += w[r];
                mp[c[r]]=true;
                r++;
            }
            ans = max(temp,ans);
            if(r==n)
                break;
            while(mp[c[r]])
            {
                temp-=w[l];
                mp[c[l]]=false;
                l++;
            }
        }
        cout<<ans<<endl;




    }
	return 0;

}
