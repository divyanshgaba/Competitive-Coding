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
        string s;
        cin>>s;
        int f =1;
        int len = s.length();
        for(int i =0;i<len;i++)
        {
            if(s[i] == 'C')
            {
                if(f > 1)
                {
                    f=-1;
                    break;
                }
                f=1;
            }
            if(s[i] == 'E')
            {
                if(f>2)
                {
                    f=-1;
                    break;
                }
                f=2;
            }
            if(s[i] == 'S')
            {
                if(f>3)
                {
                    f=-1;
                    break;
                }
                f=3;
            }

        }
        if(f==-1)
            cout<<"no\n";
        else
            cout<<"yes\n";

    }
	return 0;

}
