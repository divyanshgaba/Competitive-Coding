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
		int a[4];
		for(int i = 0;i<4;i++)
            cin>>a[i];
        sort(a,a+4);
        if(a[0]==a[1] && a[2]==a[3])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
