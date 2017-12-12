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
#define REP(i,a,b) for (int64_t i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int64_t> vi;
typedef pair<int64_t,int64_t> pi;

int main()
{
	fast;
    int64_t n;
    cin>>n;
    while(n)
    {
        int64_t a[n];
        for(int64_t i = 0;i<n;i++)
            cin>>a[i];
        int64_t left_small[n];
        left_small[0]=-1;
        int64_t right_small[n];
        right_small[n-1]=-1;
        stack<pi> st;
        st.push({a[0],0});
        for(int64_t i = 1;i<n;i++)
        {
            while(!st.empty()&&st.top().F>=a[i])
                st.pop();
            if(st.empty())
                left_small[i]=-1;
            else
                left_small[i]=st.top().S;
            st.push({a[i],i});
        }
        while(!st.empty())
            st.pop();
        st.push({a[n-1],n-1});
        for(int64_t i = n-2;i>=0;i--)
        {
            while(!st.empty()&&st.top().F>=a[i])
                st.pop();
            if(st.empty())
                right_small[i]=n;
            else
                right_small[i]=st.top().S;
            st.push({a[i],i});
        }
        int64_t answer = 0;
        int64_t ans[n];
        for(int64_t i = 0;i<n;i++)
        {
            ans[i] = max(a[i],(i-(left_small[i]+1))*a[i] + (right_small[i] - i)*a[i]);
            answer = max(answer,ans[i]);
        }
        cout<<answer<<endl;
        cin>>n;
    }
	return 0;

}
