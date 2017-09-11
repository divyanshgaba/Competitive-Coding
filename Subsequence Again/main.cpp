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
    string s;
    cin>>s;
    int k;
    cin>>k;
    unordered_map<char,int> m;
    for(auto i:s)
        m[i]++;
    for(auto i:s)
    {
        if(m[i]>=k)
            cout<<i;
    }
    cout<<endl;

	return 0;

}
