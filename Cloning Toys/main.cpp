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
	int x,y;
	cin>>x>>y;
	bool ans = true;
    if(y==0)
        ans = false;
    if(y==1&&x)
        ans = false;
    if(y>1)
    {
        if((x-y+1)<0)
            ans = false;
        if((x-y+1)%2!=0)
            ans = false;
    }
    if(ans)
        cout<<"Yes\n";
    else
        cout<<"No\n";
	return 0;

}
