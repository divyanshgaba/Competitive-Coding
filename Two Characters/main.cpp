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


int give_length(string s,int n, char x,char y)
{
    if(n<=1)
        return -1;
    int ans = 0;
    int k = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]!=x && s[i]!=y)
        {
            continue;
        }

        if(k&1)
        {
            if(s[i]!=x)
                return -1;
        }
        else
        {
            if(s[i]!=y)
                return -1;
        }
        ans++,k++;
    }
    return ans;
}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans = 0;
		string k;
		char x,y;
        for(char i = 'a';i<='z';i++)
        {
            for(char j = 'a';j<='z';j++)
            {
                if(i==j)
                    continue;
                int temp = give_length(s,n,i,j);
                if(ans < temp)
                    ans = temp,x=i,y=j;
            }
        }
        for(auto i:s)
        {
            if(i != x&&i!=y)
                continue;
            cout<<i;
        }
        cout<<endl;
        cout<<ans<<endl;
    }
	return 0;

}
