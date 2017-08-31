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

bool palindrome(string s)
{
    for(int i = 0;i<s.length()/2;i++)
    {
        if(s[i] != s[s.length()-i-1])
            return false;
    }
    return true;
}

string make_string(string s,int d)
{
    string k = "";
    int n = s.length();
    for(int i = 0;i<n;i++)
    {
        if(i == d)
            continue;
        k.push_back(s[i]);
    }
    return k;
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

		int n = s.length();
		if(palindrome(s))
        {
            cout<<-1<<endl;
            continue;
        }
        int ans =-1;
        for(int i = 0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                string t = make_string(s,i);
                if(palindrome(t))
                {
                    ans = i;
                    break;
                }
                t = make_string(s,n-i-1);
                if(palindrome(t))
                {
                    ans = n-i-1;
                    break;
                }
            }
        }
        cout<<ans<<endl;

    }
	return 0;

}
