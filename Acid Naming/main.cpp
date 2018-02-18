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

bool hydro(string s)
{
    string t ="hydro";
    if(t.length()>s.length())
        return false;
    for(int i = 0;i<t.length();i++)
        if(t[i]!=s[i])
            return false;
    return true;
}
bool poly(string s)
{
    if(s.length()<2)
        return false;
    if(s[s.length()-1]=='c'&&s[s.length()-2]=='i')
        return true;
    return false;
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
		if(hydro(s)&&poly(s))
            cout<<"non-metal acid"<<endl;
        else if(poly(s))
            cout<<"polyatomic acid"<<endl;
        else
            cout<<"not an acid"<<endl;
    }
	return 0;

}
