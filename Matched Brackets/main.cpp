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
	int a[n+1];
	for(int i = 1;i<=n;i++) cin>>a[i];
	pi dep = MP(0,0),length=MP(0,0);
	int t = 0;
    int c = 0;
    int j = 0;
    for(int i = 1;i<=n;i++)
    {
        if(a[i]==1)
        {
            t++;
            if(dep.F < t)
                dep = MP(t,i);
        }
        else
            t--;
        c++;
        if(t == 0)
        {
            if(length.F < c)
                length = MP(c,i+1-c);
            c=0;
        }
    }
    cout<<dep.F<<" "<<dep.S<<" "<<length.F<<" "<<length.S<<endl;
	return 0;

}
