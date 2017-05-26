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
	while(getline(cin,s))
    {
        int len = s.length();
        int flag =0;
        for(int i =0;i<len;i++)
        {
            if(s[i]=='/' && s[i+1] =='/')
            {
                flag = 1;
            }
            if(flag==0&&s[i]=='-'&&s[i+1]=='>')
            {
                cout<<'.';
                i++;
                continue;
            }
            cout<<s[i];
        }
        cout<<endl;
    }

	return 0;

}
