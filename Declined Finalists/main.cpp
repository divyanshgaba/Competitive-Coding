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
    int k;
    cin>>k;
    int r[k];
    for(int i = 0; i<k;i++)
        cin>>r[i];
    sort(r,r+k);
    int ans = r[k-1] - 25;
    if(ans<0)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
	return 0;

}
