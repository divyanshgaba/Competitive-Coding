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

template<typename T> T gcd(T a, T b) {
	return (b ? __gcd(a,b) : a);
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
		int x=0;
		for(int i = 0;i<n;i++)
            cin>>a[i],x=gcd(x,a[i]);
        if(x == 1)
            cout<<0<<endl;
        else
            cout<<-1<<endl;

    }
	return 0;

}
