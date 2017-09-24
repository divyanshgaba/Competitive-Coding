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
	//fast;
	int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        int n = s.length();
        if(n==1)
        {
            cout<<"NO\n";
            continue;
        }
        if(n%2==0)
        {
            if(s.substr(0,n/2)==s.substr(n/2,n/2))
                cout<<"YES\n";
            else
                cout<<"NO\n";
            continue;
        }
        int a = 0,b = 0;
        for(int i = 0,j=n/2+1;i<=n/2;i++,j++)
        {
            if(s[i]!=s[j])
            {
                a++,j--;
            }
        }
        for(int i = 0,j=n/2;j<n;i++,j++)
        {
            if(s[i]!=s[j])
            {
                b++,i--;
            }
        }
        if(a<=1||b<=1)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
	return 0;

}
