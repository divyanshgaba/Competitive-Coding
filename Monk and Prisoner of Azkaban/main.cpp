#include <iostream>
#include <algorithm>
#include <stack>
#include <array>
#define MAX 1000010
using namespace std;
long long forw[MAX];
long long backw[MAX];
long long a[MAX];
long long b[MAX];
int main()
{
    long long n;
    cin>>n;
    for(long long i =1;i<=n;i++)
    {
        cin>>a[i];
        b[n-i+1]=a[i];
        //cout<<b[n-i+1]<<" ";
    }
    stack<pair<long long,long long> > st;
    st.push(make_pair(a[1],1));
    for(long long i =2;i<=n;i++)
    {
        pair<long long,long long> current = st.top();
        while(a[i]>current.first)
        {
            forw[current.second] = i;
            st.pop();
            if(st.empty())
                break;
            current = st.top();
        }
        st.push(make_pair(a[i],i));
    }
    while(!st.empty())
    {
        forw[st.top().second]=-1;
        st.pop();
    }
    st.push(make_pair(b[1],1));
    for(long long i =2;i<=n;i++)
    {
        pair<long long,long long> current = st.top();
        while(b[i]>current.first)
        {
            backw[current.second] = i;
            st.pop();
            if(st.empty())
                break;
            current = st.top();
        }
        st.push(make_pair(b[i],i));
    }
    while(!st.empty())
    {
        backw[st.top().second]=-1;
        st.pop();
    }
    for(long long i =1;i<=n;i++)
        if(backw[i]!=-1)
            backw[i]=n-backw[i]+1;
    for(long long i =1;i<=n;i++)
        cout<<forw[i]+backw[n-i+1]<<" ";
    cout<<endl;
    return 0;
}
