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
	string s;
	cin>>s;
	int len = s.length();
	int dep =0;
	for(int i =0;i<len;i++)
    {
        if(isalpha(s[i]))
            cout<<dep<<" ";
        else
        {
            if(s[i]=='(')
                dep++;
            else
                dep--;
        }
    }
    cout<<"#\n";

	return 0;

}
