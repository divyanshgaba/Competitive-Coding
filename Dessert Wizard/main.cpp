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
		for(int i = 0;i<n;i++) cin>>a[i];
		ll curmax,curmin,leftmax[n],leftmin[n],rightmax[n],rightmin[n];
		curmax=curmin=leftmax[0]=leftmin[0] = a[0];
		for(int i = 1;i<n;i++)
        {
            curmax = max(a[i],curmax+a[i]);
            leftmax[i] = max(leftmax[i-1],curmax);
            curmin = min(a[i],curmin+a[i]);
            leftmin[i] = min(leftmin[i-1],curmin);

        }
        curmin=curmax=rightmax[n-1]=rightmin[n-1] = a[n-1];
        for(int i = n-2;i>=0;i--)
        {
            curmax = max(a[i],curmax+a[i]);
            rightmax[i] = max(rightmax[i+1],curmax);
            curmin = min(a[i],curmin+a[i]);
            rightmin[i] = min(rightmin[i+1],curmin);
        }
        ll ans = max(abs(leftmax[0]-rightmin[1]),abs(leftmin[0]-rightmax[1]));
        for(int i = 0;i<n-1;i++)
        {
            ans = max(ans,max(abs(leftmax[i]-rightmin[i+1]),abs(leftmin[i]-rightmax[i+1])));
        }
        cout<<ans<<endl;
    }
	return 0;

}
