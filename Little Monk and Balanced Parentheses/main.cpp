#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    stack<int> st;
    for(int i =1;i<=n;i++)
    {
        cin>>a[i];
    }
    int count =0;
    int ans =0;
    st.push(0);
    for(int i =1;i<=n;i++)
    {
        if(a[i]>0)
            st.push(i);
        else
        {
            int top = st.top();
            st.pop();
            if(-1*a[i] == a[top] )
            {
                if(!st.empty())
                    ans=max(ans,abs(i-st.top()));
                else
                    st.push(i);
            }
            else
                st.push(i);
        }
    }
    cout<<ans<<endl;

    return 0;
}
