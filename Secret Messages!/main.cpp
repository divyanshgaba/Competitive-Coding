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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i =0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                if(islower(s[i]))
                {
                    s[i] = (s[i]-'a' + k)%26 +'a';
                }
                else
                {
                    s[i] = (s[i]-'A' + k)%26 +'A';
                }
            }
            else if(isdigit(s[i]))
            {
                s[i] = (s[i] -'0' +k)%10 +'0';
            }
        }
        cout<<s<<endl;
    }
	return 0;

}
