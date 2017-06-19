/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
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

int flipdown(string s)
{
    int cnt = 0;
    int len = s.length();
    for(int i = 0;i<len;i++)
    {
        if(s[i] == 'U')
        {
            cnt++;
            while(s[i] == 'U')
            {
                s[i]='D';
                i++;
            }
            i--;
        }
    }
    return cnt;
}
int flipup(string s)
{
    int cnt = 0;
    int len = s.length();
    for(int i = 0;i<len;i++)
    {
        if(s[i] == 'D')
        {
            cnt++;
            while(s[i] == 'D')
            {
                s[i]='U';
                i++;
            }
            i--;
        }
    }
    return cnt;
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
        int ans = min(flipdown(s),flipup(s));
        cout<<ans<<endl;

    }
	return 0;

}
