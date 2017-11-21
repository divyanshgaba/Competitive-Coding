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
vector<char> s;
int n,p;
bool put(int i,char c)
{
    for(int j = i;j>=0;j-=p)
    {
        if((s[j]=='.'||s[j]==c)&&(s[n-j-1]==c||s[n-j-1]=='.'))
            s[j]=s[n-j-1]=c;
        else
            return false;
    }
    return true;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		cin>>n>>p;
		s = vector<char>(n,'.');
		bool t = true;
		int cnt = 0;
		bool ans = true;
		for(int i = n-1;i>=0;--i)
        {
            if(s[i]=='.')
            {
                if(t)
                    ans = ans&&put(i,'a');
                else
                    ans = ans&&put(i,'b');
                t=!t;
                cnt++;
            }
        }
        if(ans&&cnt>1)
        {
            for(int i = 0;i<n;i++)
                cout<<s[i];
            cout<<endl;
        }
        else
            cout<<"impossible\n";

    }
	return 0;

}
