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
		map<string,int> m;
		for(int i = 0;i<n;i++)
        {
            string s;
            cin>>s;
            m[s]++;
        }
        if(m["cakewalk"]>0&&m["simple"]>0&&m["easy"]>0&&(m["medium"]>0||m["easy-medium"]>0)&&(m["medium-hard"]>0||m["hard"]>0))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
	return 0;

}
