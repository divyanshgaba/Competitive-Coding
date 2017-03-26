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
        int l;
        cin>>l;
        while(l>0)
        {
            string s;
            cin>>s;
            l=l-s.length()-1;
            for(int i =s.length()-1;i>=0;i--)
                cout<<s[i];
            cout<<" ";
        }
        cout<<endl;
    }
	return 0;

}
