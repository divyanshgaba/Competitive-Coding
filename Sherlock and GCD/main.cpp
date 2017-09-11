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


int gcd(int a,int b)
{
    if(b == 0)
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
		int a[n];
		bool ans = false;
		for(int i = 0;i<n;i++)
            cin>>a[i];
        int t = a[0];
        for(int i = 1;i<n;i++)
        {
            t = gcd(t,a[i]);
        }
        if(t==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
