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
        int n,k;
        cin>>n>>k;
        set<int> s;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        int c = 0;
        while(s.find(c)!=s.end()||k>0)
        {
            if(s.find(c)==s.end())
                k--;
            c++;
        }
        cout<<c<<endl;

    }
	return 0;

}
