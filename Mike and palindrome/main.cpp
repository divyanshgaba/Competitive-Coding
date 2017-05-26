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
	int dif = 0;
	for(int i =0;i<len/2;i++)
    {
        if(s[i] != s[len-i-1])
            dif++;

    }
    if(dif>1)
    {
        cout<<"NO\n";
    }
    else if(dif==0 && len%2==0)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }


	return 0;

}
