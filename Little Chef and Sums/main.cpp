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
		for(int i = 0;i<n;i++)  cin>>a[i];
		int ele = a[0];
		int ans = 0;
		for(int i = 0;i<n;i++)
            if(ele > a[i])
                ele = a[i],ans =i;
        cout<<ans+1<<endl;
    }
	return 0;

}
