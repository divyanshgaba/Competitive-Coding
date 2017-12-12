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
	int test=0;
	while(++test)
    {
        string s;
        cin>>s;
        if(s[0]=='-')
            break;
        int ans = 0;
        stack<char> st;
        for(auto i:s)
        {
            if(st.empty())
            {
                if(i=='}')
                    ans++,st.push('{');
                else
                    st.push(i);
            }
            else
            {
                if(i=='}')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
        }
        while(!st.empty())
        {
            st.pop(),st.pop();
            ans++;
        }
		cout<<test<<". "<<ans<<endl;
    }
	return 0;

}
