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
typedef pair<char,char> pi;


int mem[26];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;
        memset(mem,0,sizeof(mem));
        for(int i =0;i<s.length();i++) mem[s[i]-'a'] =1;
        int q;
        cin>>q;
        pi a[q];
        int flag =0;
        for(int i =0;i<q;i++)
        {
            cin>>a[i].F>>a[i].S;
        }
        for(int i =q-1;i>=0;i--)
        {   if(mem[a[i].S-'a'] == 0)
            {
                flag =1;
                break;
            }
            mem[a[i].F-'a'] = 1;
            mem[a[i].S-'a'] =0;
        }
        if(flag ==0)
        {
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";

    }
	return 0;

}
