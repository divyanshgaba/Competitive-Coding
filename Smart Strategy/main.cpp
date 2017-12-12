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
		int n,q;
		cin>>n>>q;
        int d[n];
        for(int i = 0;i<n;i++)
            cin>>d[i];
        vector<int> D;
        for(int i = 0;i<n;i++)
        {
            if(d[i]>1)
                D.PB(d[i]);
            if(D.size()>31)
                break;
        }
        while(q--)
        {
            int x;
            cin>>x;
            for(auto i:D)
                x/=i;
            cout<<x<<" ";
        }
        cout<<"\n";

    }
	return 0;

}
