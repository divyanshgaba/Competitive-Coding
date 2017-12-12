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
		stack<int> st;
		int ans = 0;
		int temp = 0;
		for(auto i: s)
        {
            if(i=='<')
                st.push(1);
            else if (i=='>')
            {
                if(!st.empty())
                    st.pop(),temp+=2;
                else
                    break;
            }
            if(st.empty())
                ans+=temp,temp=0;
        }
        cout<<ans<<endl;
    }
	return 0;

}
