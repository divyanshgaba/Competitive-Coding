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
	int r;
	cin>>r;
	while(r--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool ans = true;
        bool valid = false;
        for(int i =0;i<n;i++)
        {
            if(s[i] == '.')
                continue;
            if(s[i] == 'H' && !valid)
            {
                valid = true;
                continue;
            }
            else if( s[i] == 'H' && valid)
            {
                ans = false;
                break;
            }
            if(s[i] == 'T' && valid)
            {
                valid = false;
                continue;
            }
            else if(s[i]=='T' && !valid)
            {
                ans = false;
                break;
            }
        }
        if(ans&&!valid)
            cout<<"Valid\n";
        else
            cout<<"Invalid\n";
    }
	return 0;

}

