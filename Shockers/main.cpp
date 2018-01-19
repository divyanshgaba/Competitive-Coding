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
int c[26];
int f()
{
    int ans = 0;
    for(int i = 0;i<26;i++)
        ans+=max(c[i],0);
    return ans;
}
int main()
{
	fast;
	int n;
	cin>>n;
	int ans = 0;
	bool found = false;
	char res;
	for(int i = 0;i<n;i++)
    {
        char h;
        string s;
        cin>>h>>s;
        if(found)
        {
            if(h == '!')
                ans++;
            else if(h =='?'&&res!=s[0])
                ans++;
            continue;
        }
        if(h=='!')
        {
            for(int i = 0;i<26;i++)
            {
                if(c[i]>=0)
                {
                    c[i]=-1;
                    for(auto j:s)
                    {
                        if(j-'a' == i)
                            c[i]=1;
                    }
                }
            }
        }
        else if(h=='.')
        {

            for(auto i:s)
                c[i-'a'] = -1;
        }
        else
        {
            c[s[0]-'a'] = -1;

        }
        int got = 0;
        for(int i =0;i<26;i++)
        {
            if(c[i]==0||c[i]==1)
                got++,res = i+'a';
        }
        if(got == 1) found = true;

        //for(int i = 0;i<26;i++)            cout<<c[i]<<" ";cout<<endl;

    }
    cout<<ans<<endl;
	return 0;

}
