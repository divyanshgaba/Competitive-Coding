#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int next_gr[1000001];
int next_rev[1000001];
void nge(pair<int,int> a[],int next_gr[],int n)
{
    stack<pair<int,int> > st;
    st.push(a[0]);
    for(int i =1;i<n;i++)
    {
        if(!st.empty())
        {
            pair<int,int> top = st.top();
            while(top.first < a[i].first)
            {
                next_gr[top.second] =a[i].second;
                st.pop();
                if(st.empty())
                    break;
                top = st.top();
            }
            if(top.first > a[i].first)
                st.push(a[i]);
        }
        st.push(a[i]);
    }
    while(!st.empty())
    {
        pair<int,int> top = st.top();
        next_gr[top.second] = -1;
        st.pop();
    }


}
int main()
{
    int n;
    cin>>n;
    pair<int,int> a[n+1],ar[n+1];
    for(int i =0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second =i+1;
        ar[i] =a[i];
    }
    reverse(ar,ar+n);
    nge(a,next_gr,n);
    nge(ar,next_rev,n);
    for(int i =0;i<n;i++)
    {
        //if(next_rev[i] != -1)          next_rev[i]=n-next_rev[i];
    }
    for(int i =0;i<n;i++)
    {
        cout<<next_gr[i]+next_rev[n-1-i]<<endl;
    }
    cout<<endl;
    return 0;
}
