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
		int n;
		cin>>n;
		set<int> s;
		s.insert(n);
        int h = n-1;
        int i = 1;
        bool t =true;
        while(h>0)
        {
            if(t)
                s.insert(n+i);
            else
                s.insert(n-i),i++;
            h--;
            t=!t;
        }
        for(auto i:s)
            cout<<i<<" ";
        cout<<endl;
    }
	return 0;

}
