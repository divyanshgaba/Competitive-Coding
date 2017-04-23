#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

map<string,int> mp;
vector<string> vs;
int main()
{
	fast;
	string s;
	int n;
	while(cin>>s)
    {
        if(isdigit(s[0]))
        {
            n = atoi(s.c_str());
            break;
        }
        mp[s] =0;
        vs.PB(s);
    }
    for(int i =0;i<n;i++)
    {
        cin>>s;
        mp[s] =1;
    }
    for(auto s:vs)
    {
        if(mp[s] == 0)
            cout<<s<<" ";
        else
        {
            cout<<"<b>"<<s<<"</b> ";
        }
    }
	return 0;

}
