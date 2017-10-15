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
		vector<ll> a;
		for(int i = 0;i<n;i++)
        {
            ll x;
            cin>>x;
            a.PB(x);
        }
        sort(a.begin(),a.end());
        vector<ll> ans,s;
        int i;
        for(i = 0;i<n;)
        {
            if(a[i]==0)
                ans.PB(a[i]),i++;
            else
                break;
        }
        int zeros = i;
        for(;i<n-3;)
        {
            if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i+2]==1)
                ans.PB(a[i]),i++;
            else
                break;
        }
        bool t = true;
        for(;i<n;i++,t=!t)
        {
            if(t)
                ans.PB(a[i]);
            else
                s.PB(a[i]);
        }
        for(int i = s.size()-1;i>=0;i--)
            ans.PB(s[i]);
        ll prod = 0;
        for(int i = 0;i<n-1;i++)
        {
            prod += (ans[i]*ans[i+1]);
        }
        cout<<prod<<endl;
        int one = 0,zero =0;
        for(auto i:ans)
        {
            if(i==1)
                one++;
            if(i==0)
                zero++;
        }
        if(one+zero+1>=n)
            swap(ans[n-1],ans[n-2]);
        if(ans[n-1]>ans[zeros])
            swap(ans[n-1],ans[zeros]);
        for(auto i:ans)
            cout<<i<<" ";
        cout<<endl;
    }
	return 0;

}
