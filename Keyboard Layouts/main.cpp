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
	//cin>>test;
	while(test--)
    {
		string f,s;
		cin>>f>>s;
		unordered_map<char,char> m;
		for(int i = 0;i<26;i++)
        {
            m[f[i]]=s[i];
        }
		string cipher;
		cin>>cipher;
		for(auto i:cipher)
        {
            if(isdigit(i))
            {
                cout<<i;
                continue;
            }
            if(islower(i))
            {
                cout<<m[i];
                continue;
            }
            if(isupper(i))
            {
                cout<<char(m[i+32]-32);
                continue;
            }

        }
        cout<<endl;

    }
	return 0;

}
