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
string s;
int n;

int main()
{
	fast;
	cin>>s;
	n = s.length();
    int ans = 0;
	for(int i = 0;i<n;i++)
    {
        stack<char> st;
        stack<char> star;
        for(int j = i;j<n;j++)
        {
            if(s[j]=='?')
            {
                if(st.empty())
                    st.push('(');
                else
                    st.pop(),star.push('(');
            }
            if(s[j]==')')
            {
                if(st.empty())
                {
                    if(star.empty())
                        break;
                    star.pop();
                    st.push('(');
                }
                else
                {
                    if(st.top() =='(')
                        st.pop();
                    else
                    {
                        if(star.empty())
                            break;
                        else
                            st.push('('),star.pop();
                    }
                }
            }
            if(s[j] == '(')
            {
                st.push('(');
            }
            if(st.empty())
                ans++;
        }

    }
    cout<<ans<<endl;
	return 0;

}
