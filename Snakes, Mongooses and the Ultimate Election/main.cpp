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
        string s;
        cin>>s;
        int len = s.length();
        int sn=0,mn=0;
        for(int i =0;i<len;i++)
        {
            if(s[i]=='s')
                sn++;
            else
                mn++;

        }
        for(int i =0;i<len;i++)
        {
            if(s[i] == 'm')
            {
                if(i!=0 && s[i-1] == 's')
                {
                    sn--;
                    s[i-1]='0';
                }
                else if(i!=len-1&& s[i+1]=='s')
                {
                    sn--;
                    s[i+1]='0';
                }
            }
        }
        if(mn>sn)
            cout<<"mongooses\n";
        else if(sn > mn)
            cout<<"snakes\n";
        else
            cout<<"tie\n";

    }
	return 0;

}
