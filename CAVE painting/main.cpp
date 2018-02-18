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
	ll n,k;
	cin>>n>>k;
    if(k>=45)
        cout<<"No\n";
    else
    {
        set<int> s;
        for(int i = 1;i<=k;i++)
            s.insert(n%i);
        if(s.size() == k)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
	return 0;

}
