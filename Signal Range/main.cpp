#include <iostream>
#include <stack>
using namespace std;
long long forw[1000010];
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n;
        cin>>n;
        long long a[n];
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
            forw[i]=1;
        }
        stack<pair<pair<long long,long long>,long long> > st;
        st.push(make_pair(make_pair(a[0],0),1));
        for(int i =1;i<n;i++)
        {
            pair<pair<long long,long long>,long long> current = st.top();
            while(a[i]>=current.first.first)
            {
                //forw[current.first.second] += current.second;
                forw[current.first.second] = current.second;
                st.pop();
                forw[i]+=current.second;
                if(st.empty())
                    break;
                current = st.top();
            }
            st.push(make_pair(make_pair(a[i],i),forw[i]));
        }
        while(!st.empty())
        {
            //forw[st.top().first.second] = st.top().second;
            st.pop();
        }
        for(int i =0;i<n;i++)
            cout<<forw[i]<<" ";
        cout<<endl;

    }
    return 0;
}
