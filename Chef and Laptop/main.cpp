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
		int a[n];
		map<int,int> m;
		for(int i = 0;i<n;i++) cin>>a[i],m[a[i]]++;
		int ans;
		for(auto i:m)
            if(i.S==1)
            {
                ans = i.F;
                break;
            }
        cout<<ans<<endl;
    }
	return 0;

}
