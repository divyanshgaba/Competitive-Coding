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


int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;
        int len = s.length();
        int c = 0;
        for(int i =0;i<len;i++)
        {
            if(c==0&&s[i] == '1')
                c=1;
            if(c==1&&s[i]=='0')
                c=2;
            if(c==2&&s[i] == '1')
            {
                c=3;
                break;
            }

        }
        if(c==1 || c == 2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
