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
	int n;
	cin>>n;
	string s[n];
	for(int i =0;i<n;i++)
        cin>>s[i];
    int fin = 1e9;
    for(int i =0;i<n;i++)
    {
        int ans = 0;
        for(int j =0;j<n;j++)
        {
            auto found = (s[j]+s[j]).find(s[i]);
            if(found!=string::npos)
            {
                ans+=found;
            }
            else
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        fin = min(ans,fin);
    }
    cout<<fin<<endl;

	return 0;

}
