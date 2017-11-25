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
    int n;
    cin>>n;
    while(n)
    {
        int a[n];
        for(int i = 0;i<n;i++)
            cin>>a[i];
        bool ans = true;
        int cnt = 1;
        stack<int> st;
        int i = 0;
        while(i<n||!st.empty())
        {
            if(i<n&&a[i]==cnt)
            {
                cnt++;
                i++;
                continue;
            }
            if(!st.empty()&&st.top()==cnt)
            {
                st.pop();
                cnt++;
                continue;
            }
            if(i<n)
                st.push(a[i]),i++;
            else
            {
                ans = false;
                break;
            }
        }
        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";
        cin>>n;


    }
	return 0;

}
