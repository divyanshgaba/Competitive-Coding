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
	int len = s.length();
	int ans =0;
	bool t = true;
	for(int i = len-1;i>=0;--i)
    {
        if(t&&s[i]=='1')
        {
            ans++;
            t = false;
            continue;
        }
        if(!t && s[i]=='0')
        {
            ans++;
            t= true;
        }

    }
    cout<<ans<<endl;

	return 0;

}
