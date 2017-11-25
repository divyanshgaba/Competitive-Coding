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
int n,k;
const ll mod = 1e9 + 7;
int main()
{
	fast;
    cin>>n>>k;
    ll t[max(n,k)+1];
    ll s = 0;
    for(int i = 0;i<k;i++)
        t[i] = 1,s+=t[i];
    for(int i = k;i<n;i++)
    {
        t[i] = s;
        s=(s-t[i-k]+t[i])%mod;
        if(s<0)
            s+=mod;
    }
    cout<<t[n-1]<<endl;
	return 0;

}
