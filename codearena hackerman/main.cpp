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
	int test;
	cin>>test;
	while(test--)
    {
        string a,b;
        cin>>a>>b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int c=atoi(a.c_str()),d = atoi(b.c_str());
        int e = c+d;
        string s = to_string(e);
        reverse(s.begin(),s.end());
        cout<<atoi(s.c_str())<<endl;

    }
	return 0;

}
