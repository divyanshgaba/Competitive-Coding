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
int n;
map<string,ll> m;
bool valid(string a,string b)
{
    set<char> s;
    s.insert(a.begin(),a.end());
    s.insert(b.begin(),b.end());
    if(s.size() == 10)
        return true;
    return false;
}
int main()
{
	fast;
	cin>>n;

	for(int i = 0;i<n;i++)
    {
        set<char> t;
        string s;
        cin>>s;
        t.insert(s.begin(),s.end());
        s.clear();
        for(auto j:t)
           s.push_back(j);
        m[s]++;
    }
    ll ans = 0;
    for(auto i:m)
    {
        for(auto j:m)
        {
            if(i.F!=j.F && valid(i.F,j.F))
            {
                ans += i.S * j.S;
            }
        }
    }
    ans += (m["0123456789"]*(m["0123456789"] - 1));
    cout<<(ans/2LL)<<endl;
	return 0;

}
