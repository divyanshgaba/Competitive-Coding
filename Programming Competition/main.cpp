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

bool cmp(pair<int,string> a,pair<int,string> b)
{
    return a.F>b.F;
}

int main()
{
	fast;
	int n;
	cin>>n;
	vector<pair<int,string>> v;
	for(int i = 0;i<n;i++)
    {
        string a;
        cin>>a;
        int b,c;
        cin>>b>>c;
        v.PB(MP(c-b,a));
    }
    stable_sort(v.begin(),v.end(),cmp);
    cout<<v[0].S<<" "<<v[0].F<<endl;
	return 0;

}
