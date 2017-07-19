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

void solve()
{
    int n,h;
    cin>>n>>h;
    int a[n];
    int pos = 0;
    bool box = false;
    for(int i = 0;i<n;i++) cin>>a[i];
    while(1)
    {
        int q;
        cin>>q;
        if(q==0)
            break;
        if(q == 1)
        {
           if(pos!=0)
                pos--;

        }
        else if(q==2)
        {
            if(pos != n-1)
                pos++;
        }
        else if(q==3)
        {
            if(box==false && a[pos]!=0)
                a[pos]--,box=true;
        }
        else
        {
            if(box)
            {
                if(a[pos] + 1 <= h)
                    a[pos]++,box=false;
            }
        }


    }
    for(int i = 0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
