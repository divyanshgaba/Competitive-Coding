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

bool gre[100001];


int main()
{
	fast;
	string s;
	cin>>s;
	int len = s.length();
	char ch = s[len-1];
	for(int i =len-1;i>=0;i--)
    {
        if(s[i]>=ch)
        {
            gre[i] =true;
        }
        else
        {
            ch = s[i];
        }
    }
    stack<char> st;
    for(int i =0;i<len;i++)
    {
        if(!gre[i])
        {
            while(!st.empty())//&&st.top() < s[i])
            {
                    cout<<st.top();
                    st.pop();
            }
        }
        st.push(s[i]);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    //for(int i =0;i<len;i++)        cout<<gre[i];
	return 0;

}
