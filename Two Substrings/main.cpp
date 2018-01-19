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

int main()
{
	fast;
	string s;
	cin>>s;
	int n = s.length();
	bool ab = false, ba = false;
	for(int i = 0;i<n-1;i++)
    {
        if(s[i] == 'A'&&s[i+1]=='B')
        {
            if(!ab)
            {
                ab = true;
                i++;
                continue;
            }
        }
        if(!ab)
            continue;

        if(s[i]=='B'&&s[i+1]=='A')
        {
            if(!ba)
            {
                ba = true;
                i++;
                continue;
            }
        }
    }
    bool t = ab&&ba;
    ab = ba = false;
	for(int i = 0;i<n-1;i++)
    {

        if(s[i]=='B'&&s[i+1]=='A')
        {
            if(!ba)
            {
                ba = true;
                i++;
                continue;
            }
        }
        if(!ba)
            continue;

        if(s[i] == 'A'&&s[i+1]=='B')
        {
            if(!ab)
            {
                ab = true;
                i++;
                continue;
            }
        }
    }
    if(t||(ab&&ba))
    {
        cout<<"YES\n";
    }
    else
        cout<<"NO\n";
	return 0;

}
