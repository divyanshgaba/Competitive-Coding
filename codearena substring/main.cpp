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

int c[5];
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        string s;
        cin>>s;
        memset(c,0,sizeof(c));
        int len = s.length();
        for(int i =0;i<len;i++)
        {
            switch(s[i])
            {
                case 'r':
                    c[0]++;
                    break;
                case 'u':
                    c[1]++;
                    break;
                case 'b':
                    c[2]++;
                    break;
                case 'y':
                    c[3]++;
                    break;
            }
        }
        int ans =c[0];
        for(int i =1;i<4;i++)
        {
            ans=min(ans,c[i]);
        }
        cout<<ans<<"\n";
    }
	return 0;

}
