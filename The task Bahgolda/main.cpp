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
	int n;
	cin>>n;
	if(n%2!=0)
    {
        int cnt = 1+(n-3)/2;
        cout<<cnt<<endl;
        cout<<3<<" ";
        for(int  i =1;i<cnt;i++)
            cout<<2<<" ";
        cout<<endl;
    }
    else
    {
        cout<<n/2<<endl;
        for(int i = 0;i<n/2;i++)
            cout<<2<<" ";
        cout<<endl;
    }
	return 0;

}
