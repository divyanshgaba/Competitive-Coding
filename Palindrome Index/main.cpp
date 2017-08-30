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
        if(s[s.length()-i-1] != s[i])
            return false;
    }
    return true;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		string s;
		cin>>s;
		int n = s.length(),ans = -1;
		for(int i = 0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                if(palindrome(s.substr(0,i) + s.substr(i+1,n-i)))
                {
                    ans = i;
                    break;
                }
                else
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
