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
	int n,m;
	cin>>n>>m;
	map<string,string> me;
	for(int i = 0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        me[b]=a;
    }
    for(int i = 0;i<m;i++)
    {
        string a,b;
        cin>>a>>b;
        string c = b;
        c.pop_back();
        cout<<a<<" "<<b<<" #"<<me[c]<<endl;
    }
	return 0;

}
