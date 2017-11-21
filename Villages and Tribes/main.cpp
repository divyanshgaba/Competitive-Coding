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

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		string s;
		cin>>s;
		int n = s.length();
		int a,b;
		a=b=0;
		for(int i = 0;i<n;i++)
        {
            int j = i;
            if(s[i]=='A')
            {
                a++;
                bool t = false;
                for(i++;i<n;i++)
                {
                    if(s[i]=='A')
                    {
                        t = true;
                        break;
                    }
                    if(s[i]=='B')
                        break;
                }
                if(t)
                    a +=(i-j-1),i--;
                else
                    i--;
            }
            else if(s[i]=='B')
            {
                b++;
                bool t = false;
                for(i++;i<n;i++)
                {
                    if(s[i]=='B')
                    {
                        t = true;
                        break;
                    }
                    if(s[i]=='A')
                        break;
                }
                if(t)
                    b +=(i-j-1),i--;
                else
                    i--;
            }
        }
        cout<<a<<" "<<b<<endl;
    }
	return 0;

}
