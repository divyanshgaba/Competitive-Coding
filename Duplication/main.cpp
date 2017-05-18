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

string s ="0";
void build()
{
    if(s.length() > 1000)
        return;
    int t = s.length();
    for(int i =0;i<t;i++)
    {
        if(s[i] == '0')
            s+='1';
        else
            s+='0';
    }
    build();
}

int main()
{
	fast;
	int q;
	cin>>q;
	build();
	for(int i =0;i<q;i++)
    {
        int x;
        cin>>x;
        cout<<s[x]<<endl;

    }
	return 0;

}
