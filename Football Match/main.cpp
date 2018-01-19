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
		if(n==0)
        {
            cout<<"Draw\n";
            continue;
        }
		map<string,int> m;
		string s;
		for(int i = 0;i<n;i++)
            cin>>s,m[s]++;
        vector<pair<string,int>> v;
        for(auto i:m)
            v.PB(i);
        if(v.size()==1)
            cout<<v[0].F<<endl;
        else
        {
            if(v[0].S==v[1].S)
                cout<<"Draw\n";
            else if(v[0].S<v[1].S)
                cout<<v[1].F<<endl;
            else
                cout<<v[0].F<<endl;
        }
    }
	return 0;

}
