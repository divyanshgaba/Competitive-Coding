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

int mem[101];

int main()
{
	fast;
	string s;
	cin>>s;
	for(int i =0;i<s.length();i++)
    {
        if(s[i]=='a'||s[i]=='u'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='y')
            mem[i]=1;
    }
    int flag =1;
    for(int i =0;i<s.length()-1;i++)
    {
        if(s[i]==s[i+1] || (mem[i]==mem[i+1] && mem[i]==1))
        {
            flag=0;
            break;
        }
    }
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;

}
