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

const int MAX = 1e5 +5;

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;
        ll len = s.length();
        ll cnt  =0;
        ll ans  =0;
        for(int i =0;i<len-1;i++)
        {
            if(s[i] == '1')
                cnt++;
            if(s[i]=='1' && s[i+1]=='0')
            {
                int j;
                for(j = i+2;j<len;j++)
                    if(s[j]=='1')
                        break;
                j--;
                ans = ans + cnt + cnt*(j-i);
                i = j;


            }
        }
        cout<<ans<<endl;

    }
	return 0;

}
