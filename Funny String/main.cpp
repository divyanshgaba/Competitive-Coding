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
	int test=1;
	cin>>test;
	while(test--)
    {
		string s;
		cin>>s;
		int n = s.length();
		string k = s;
		reverse(k.begin(),k.end());
		bool ans = true;
		for(int i = 1;i<n;i++)
        {
            if(abs(s[i]-s[i-1]) != abs(k[i]-k[i-1]))
                ans = false;
        }
        if(ans)
            cout<<"Funny\n";
        else
            cout<<"Not Funny\n";
    }
	return 0;

}
