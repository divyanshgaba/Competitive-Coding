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
    int n,q;
    cin>>n>>q;
    ll a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    while(q--)
    {
        int x,l,r;
        cin>>x>>l>>r;
        if(x ==1)
        {
            int cnt = 0,j=0;
            int ans = l;
            ll prev = a[l-1];
            for(int i = l;i<n&&j<r;i++)
            {
                if(cnt >=100)
                    break;
                if(prev < a[i])
                {
                    j++;
                    prev = a[i];
                    cnt = 0;
                    ans = i+1;
                }
                else
                    cnt++;
            }
            cout<<ans<<endl;
        }
        else
        {
            ll val;
            cin>>val;
            for(int i = l-1;i<r;i++)
            {
                a[i]+=val;
            }

        }

    }
	return 0;

}
