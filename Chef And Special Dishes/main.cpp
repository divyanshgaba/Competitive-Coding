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
int one[30],two[30];

bool check(string s)
{
    memset(one,0,sizeof(one));
    memset(two,0,sizeof(two));
    int dif=0;
    int len = s.length();
    if(len%2!=0)
    {
        int j = len/2+1;
        for(int i =0;i<=len/2;i++)
        {
            if(s[i] != s[j++])
            {
                dif++;
                j++;
            }
            if(dif==2)
                return false;
        }
    }
    else
    {
        REP(i,0,len/2-1)
        {
            if(s[i]!=s[i+len/2])
                return false;
        }
    }
    return true;
}

int main()
{
	fast;
	int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        if(check(s))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
