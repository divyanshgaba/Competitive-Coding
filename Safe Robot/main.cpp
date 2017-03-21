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
	int test;
	cin>>test;
    while(test--)
    {
        int n,m;
        string s;
        cin>>n>>m>>s;
        int mu=0,ml=0,mr=0,md=0;
        int l=0,u=0,d=0,r=0;
        int flag=0;
        int len = s.length();
        REP(i,1,n)
        {
            REP(j,1,m)
            {
                u=i;
                l=j;
                flag=0;
                REP(k,0,len-1)
                {
                    switch(s[k])
                    {
                    case 'L':
                        l--;
                        break;
                    case 'R':
                        l++;
                    break;
                    case 'D':
                            u++;
                        break;
                    case 'U':u--;
                            break;
                    }
                    if(l==0 || l == m+1 || u==0 || u== n+1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }

            if(flag==0)
                break;
        }
        if(flag==1)
        {
            cout<<"unsafe\n";
        }
        else
        {
            cout<<"safe\n";
        }
    }
	return 0;

}
