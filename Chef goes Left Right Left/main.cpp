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
		int n,r;
		cin>>n>>r;
		int a[n];
		for(int i = 0;i<n;i++)
            cin>>a[i];
        int low = 0,high = 1e9+1;
        bool ans = true;
        for(int i = 0;i<n-1;i++)
        {
            if(r<a[i])
            {
                if(high < a[i])
                {
                    ans = false;
                    break;
                }
                high = a[i];
            }
            else if(r>a[i])
            {
                if(low > a[i])
                {
                    ans = false;
                    break;
                }
                low = a[i];
            }
            else
            {
                ans = false;
                break;
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
