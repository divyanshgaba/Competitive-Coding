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

int mem[26];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(mem,0,sizeof(mem));
        string s;
        cin>>s;
        int len = s.length();
        for(int i =0;i<len;i++)
            mem[s[i]-'a']++;
        int ans =0;
        for(int i =0;i<26;i++)
        {
            if(mem[i]%2 != 0)
            {
                ans+=1;
                len++;
            }
        }
        if(ans>0&&len%2==0)
            ans--;
        cout<<ans<<endl;
    }
	return 0;

}
